#!/bin/bash

# =================================================================================
# Enhanced Comprehensive Test and Validation Script for P4EntregaFinal (v3)
#
# Corrige los IDs de inmueble y publicación hardcodeados en el caso de prueba 4
# para que coincidan con los valores generados dinámicamente durante la ejecución.
# =================================================================================

# --- Configuration ---
EXEC_NAME="./main"
STDOUT_LOG="enhanced_test_output.log"
VALGRIND_LOG="enhanced_valgrind_report.log"
INPUT_FILE_PREFIX="test_input_"

# Test counters
PASSED_TESTS=0
FAILED_TESTS=0
TOTAL_TESTS=0

# --- Colors for output ---
COLOR_GREEN='\033[0;32m'
COLOR_RED='\033[0;31m'
COLOR_YELLOW='\033[1;33m'
COLOR_BLUE='\033[0;34m'
COLOR_NC='\033[0m'

# --- Helper Functions ---
function print_header {
    echo -e "\n${COLOR_BLUE}--- $1 ---${COLOR_NC}"
}

function run_check {
    local description="$1"
    local search_string="$2"
    local log_file="$3"
    local should_not_exist="$4" # 'true' if we are checking for absence

    ((TOTAL_TESTS++))
    echo -n -e "${COLOR_YELLOW}[VERIFICANDO]${COLOR_NC} $description..."

    if [ "$should_not_exist" = "true" ]; then
        if ! grep -q -e "$search_string" "$log_file"; then
            echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
            ((PASSED_TESTS++))
        else
            echo -e " ${COLOR_RED}FALLÓ (se encontró inesperadamente)${COLOR_NC}"
            ((FAILED_TESTS++))
        fi
    else
        if grep -q -e "$search_string" "$log_file";
        then
            echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
            ((PASSED_TESTS++))
        else
            echo -e " ${COLOR_RED}FALLÓ${COLOR_NC}"
            ((FAILED_TESTS++))
        fi
    fi
}


# --- Test Case Functions ---

function test_original_scenario {
    print_header "CASO DE PRUEBA ORIGINAL: Flujo completo End-to-End"
    local INPUT_FILE="${INPUT_FILE_PREFIX}original.txt"
    local LOG_FILE="${STDOUT_LOG}"

    cat > "$INPUT_FILE" << EOF
11
21
6
2025
9
1
2
jorge88
password123
Jorge II
jorge2@mail.com
111111
222222
1
2
test_propietario
testpass123
Propietario de Prueba
proptest@email.com
CTA12345
099000111
1
1
Calle de Prueba 987
987
150
2022
1
2
0
8
casasur123
9
5
soledadf
casasur123
2
casasur123
9
1
Se vende casa de prueba en excelente estado.
350000
6
soledadf
3
1
300000
400000
1
1
18
7
soledadf
casasur123
4
9
1
4
0
0
EOF

    valgrind --leak-check=full --log-file="$VALGRIND_LOG" "$EXEC_NAME" < "$INPUT_FILE" > "$LOG_FILE" 2>&1
    
    run_check "Maneja creación de usuarios duplicados" "Error al crear el usuario" "$LOG_FILE"
    run_check "Suscripción se realizó con éxito" "Suscripcion realizada correctamente." "$LOG_FILE"
    run_check "Notificación fue recibida por 'soledadf'" "- Inmobiliaria: casasur123, Codigo Inmueble: 9, Tipo Publicacion: Venta" "$LOG_FILE"
    run_check "Desuscripción se realizó con éxito" "Desuscripcion realizada correctamente." "$LOG_FILE"
    
    ((TOTAL_TESTS++))
    echo -n -e "${COLOR_YELLOW}[VERIFICANDO]${COLOR_NC} Propiedad fue eliminada de los listados..."
    FINAL_LOG_PART=$(sed '0,/¿Desea eliminar?: (1: Si, 0: No)/d' "$LOG_FILE")
    if echo "$FINAL_LOG_PART" | grep -q "Codigo: 9,"; then
        echo -e " ${COLOR_RED}FALLÓ (se encontró inesperadamente)${COLOR_NC}"
        ((FAILED_TESTS++))
    else
        echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
        ((PASSED_TESTS++))
    fi
}

function test_publication_vigency {
    print_header "NUEVO CASO 1: Lógica de Vigencia de Publicaciones (esActiva)"
    local INPUT_FILE="${INPUT_FILE_PREFIX}vigency.txt"
    local LOG_FILE="vigency_test.log"
    cat > "$INPUT_FILE" << EOF
9
11
30
12
2024
2
idealhome
7
1
Venta mas nueva y mejorada
460000
3
1
450000
500000
2
0
0
EOF

    "$EXEC_NAME" < "$INPUT_FILE" > "$LOG_FILE" 2>&1

    run_check "Publicación nueva (vigente) aparece en la consulta" "texto: Venta mas nueva y mejorada" "$LOG_FILE"
    run_check "Publicación antigua (no vigente) NO aparece" "Aptamente en excelentes condiciones de 80 m" "$LOG_FILE" "true"
}

function test_notification_clearing {
    print_header "NUEVO CASO 2: Limpieza de Notificaciones"
    local INPUT_FILE="${INPUT_FILE_PREFIX}notification.txt"
    local LOG_FILE="notification_test.log"
    cat > "$INPUT_FILE" << EOF
9
2
casasur123
6
0
Alquiler temporal para notificar
15000
6
luisito23
6
luisito23
0
EOF

    "$EXEC_NAME" < "$INPUT_FILE" > "$LOG_FILE" 2>&1

    csplit -s -f "notif_part_" "$LOG_FILE" /CONSLTAR/ '{*}'

    run_check "Notificación es recibida en la primera consulta" "Texto: Alquiler temporal para notificar" "notif_part_01"
    run_check "Notificaciones están vacías en la segunda consulta" "No tiene notificaciones pendientes." "notif_part_02"
    rm -f notif_part_*
}

function test_non_existent_entity {
    print_header "NUEVO CASO 3: Manejo de Error al Eliminar Inmueble Inexistente"
    local INPUT_FILE="${INPUT_FILE_PREFIX}nonexistent.txt"
    local LOG_FILE="nonexistent_test.log"
    cat > "$INPUT_FILE" << EOF
9
4
999
0
EOF

    "$EXEC_NAME" < "$INPUT_FILE" > "$LOG_FILE" 2>&1

    run_check "Programa maneja error de inmueble inválido" "Inmueble ingresado no es valido" "$LOG_FILE"
}

function test_apartment_and_rent {
    print_header "NUEVO CASO 4: Cobertura de Apartamento y Alquiler"
    local INPUT_FILE="${INPUT_FILE_PREFIX}apartment.txt"
    local LOG_FILE="apartment_test.log"
    
    # <<< CORRECCIÓN: Se usan los IDs correctos para el nuevo inmueble (9) y la nueva publicación (18)
    cat > "$INPUT_FILE" << EOF
9
1
2
apto_owner
passapto
Dueño Apto
apto@owner.com
BANC123
091111111
1
0
Av. Nueva 101
101
80
2023
8
1
5500
0
8
idealhome
9
2
idealhome
9
0
Alquiler de nuevo apto
35000
3
0
30000
40000
2
1
18
0
EOF
    
    "$EXEC_NAME" < "$INPUT_FILE" > "$LOG_FILE" 2>&1

    run_check "Publicación de Alquiler de Apartamento se lista" "texto: Alquiler de nuevo apto,.*inmobiliaria: IHome" "$LOG_FILE"
    run_check "Detalle del Apartamento muestra gastos comunes" "gastos comunes: 5500" "$LOG_FILE"
    run_check "Detalle del Apartamento muestra el piso" "piso: 8" "$LOG_FILE"
}


# --- Main Execution ---

print_header "Paso 1: Compilando el Proyecto"
make clean &> /dev/null
make all &> build_log.txt
if [ $? -ne 0 ]; then
    echo -e "${COLOR_RED}La Compilación Falló. Revisa 'build_log.txt' para más detalles.${COLOR_NC}"
    exit 1
fi
echo -e "${COLOR_GREEN}Compilación exitosa.${COLOR_NC}"

# --- Run All Tests ---
test_original_scenario
test_publication_vigency
test_notification_clearing
test_non_existent_entity
test_apartment_and_rent

# --- Final Valgrind Check on the main scenario ---
print_header "Paso Final: Verificación de Fugas de Memoria (Valgrind)"
((TOTAL_TESTS++))
echo -n -e "${COLOR_YELLOW}[VERIFICANDO]${COLOR_NC} Fugas de memoria con Valgrind..."
if grep -q -E 'definitely lost|indirectly lost' "$VALGRIND_LOG"; then
    echo -e " ${COLOR_RED}FALLÓ${COLOR_NC}"
    ((FAILED_TESTS++))
    echo -e "\n${COLOR_YELLOW}NOTA IMPORTANTE SOBRE VALGRIND:${COLOR_NC}"
    echo "La falla de Valgrind podría deberse a las instancias Singleton. Aunque el SO recupera esta memoria, Valgrind lo reporta como fuga. Tu 'limpiarRecursos()' en main.cpp debería manejar esto. Si la fuga persiste, revisa que todos los 'new' tengan su 'delete'."
    grep -E 'definitely lost|indirectly lost' "$VALGRIND_LOG"
else
    echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
    ((PASSED_TESTS++))
fi
echo ""


# --- Resumen Final ---
echo "==================== Resumen de la Prueba Mejorada ===================="
echo "Total de verificaciones: $TOTAL_TESTS"
echo -e "Verificaciones ${COLOR_GREEN}exitosas: $PASSED_TESTS${COLOR_NC}"
echo -e "Verificaciones ${COLOR_RED}fallidas: $FAILED_TESTS${COLOR_NC}"
echo "====================================================================="

if [ "$FAILED_TESTS" -eq 0 ]; then
    echo -e "${COLOR_GREEN}¡Felicidades! Todas las pruebas pasaron. El programa es funcionalmente más robusto.${COLOR_NC}"
else
    echo -e "${COLOR_RED}Algunas pruebas fallaron. Revisa la salida y los archivos de registro generados para más detalles.${COLOR_NC}"
fi

# Cleanup
rm -f ${INPUT_FILE_PREFIX}*.txt *.log

exit "$FAILED_TESTS"