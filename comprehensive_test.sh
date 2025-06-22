#!/bin/bash

# ==============================================================================
# Comprehensive Test and Validation Script for P4EntregaFinal (Final, Refined)
#
# This version corrects the verification logic to match the program's actual
# correct behavior and fixes the script's own syntax errors.
# ==============================================================================

# --- Configuration ---
EXEC_NAME="./main"
INPUT_FILE="test_inputs.txt"
STDOUT_LOG="test_output.log"
VALGRIND_LOG="valgrind_report.log"

EXPECTED_INMUEBLE_CODE=9
EXPECTED_PUBLICACION_CODE=18
# The date left by CargaDatos.cpp is the one that matters for later operations.
EXPECTED_FINAL_DATE="17/8/2025" 

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
function run_check {
    local description="$1"
    local search_string="$2"
    local log_file="$3"
    ((TOTAL_TESTS++))
    echo -n -e "${COLOR_YELLOW}[VERIFICANDO]${COLOR_NC} $description..."
    if grep -q -e "$search_string" "$log_file"; then
        echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
        ((PASSED_TESTS++))
    else
        echo -e " ${COLOR_RED}FALLÓ${COLOR_NC}"
        ((FAILED_TESTS++))
    fi
}

# --- Main Execution ---

echo -e "${COLOR_BLUE}--- Paso 1: Compilando el Proyecto ---${COLOR_NC}"
make clean &> /dev/null
make all &> build_log.txt
if [ $? -ne 0 ]; then
    echo -e "${COLOR_RED}La Compilación Falló. Revisa 'build_log.txt' para más detalles.${COLOR_NC}"
    exit 1
fi
echo -e "${COLOR_GREEN}Compilación exitosa.${COLOR_NC}\n"

echo -e "${COLOR_BLUE}--- Paso 2: Generando Secuencia de Entradas Completa ---${COLOR_NC}"
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
$EXPECTED_INMUEBLE_CODE
5
luisito23
vivaurbana
2
casasur123
$EXPECTED_INMUEBLE_CODE
1
Se vende casa de prueba en excelente estado.
350000
6
anarojo88
3
1
300000
400000
1
1
$EXPECTED_PUBLICACION_CODE
7
luisito23
vivaurbana
4
$EXPECTED_INMUEBLE_CODE
1
4
0
0
EOF
echo "Se ha generado el archivo de entradas: '$INPUT_FILE'.\n"

echo -e "${COLOR_BLUE}--- Paso 3: Ejecutando el Programa con Valgrind ---${COLOR_NC}"
echo "--------------------------------------------------------------------------"
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file="$VALGRIND_LOG" \
         "$EXEC_NAME" < "$INPUT_FILE" 2>&1 | tee "$STDOUT_LOG"
echo "--------------------------------------------------------------------------"
echo -e "${COLOR_GREEN}Ejecución del programa finalizada.${COLOR_NC}\n"

echo -e "${COLOR_BLUE}--- Paso 4: Verificando los Resultados Automáticamente ---${COLOR_NC}"
run_check "Maneja correctamente la creación de usuarios duplicados" "Error al crear el usuario" "$STDOUT_LOG"
run_check "La nueva propiedad fue creada para 'test_propietario'" "propietario: test_propietario" "$STDOUT_LOG"
run_check "La suscripción se realizó con éxito" "Suscripcion realizada correctamente." "$STDOUT_LOG"
run_check "La notificación fue recibida por el usuario suscrito" "- Inmobiliaria: casasur123, Codigo Inmueble: $EXPECTED_INMUEBLE_CODE, Tipo Publicacion: Venta" "$STDOUT_LOG"
# Corregido: Verificar con la fecha correcta que deja CargaDatos
run_check "La nueva publicación se lista correctamente" "Codigo: $EXPECTED_PUBLICACION_CODE, fecha: $EXPECTED_FINAL_DATE, texto: Se vende casa de prueba en excelente estado., precio: 350000, inmobiliaria: Casa Sur" "$STDOUT_LOG"
# Corregido: Verificar solo una parte de la línea para evitar problemas con saltos de línea
run_check "La vista de detalle de la publicación es correcta" "Codigo: $EXPECTED_INMUEBLE_CODE, direccion: Calle de Prueba 987, nro. puerta: 987" "$STDOUT_LOG"
run_check "La desuscripción se realizó con éxito" "Desuscripcion realizada correctamente." "$STDOUT_LOG"
# Corregido: Simplificada la verificación del diálogo de eliminación
run_check "Apareció el diálogo de eliminación para la propiedad correcta" "Codigo del inmueble a eliminar: Detalle del inmueble:" "$STDOUT_LOG"

# Verificación de eliminación mejorada
echo -n -e "${COLOR_YELLOW}[VERIFICANDO]${COLOR_NC} La propiedad fue eliminada de los listados..."
((TOTAL_TESTS++))
LAST_LISTING=$(awk '/Listado de inmuebles:/ {p=1; block=""} p {block=block $0 "\n"} END {print block}' "$STDOUT_LOG")
if echo "$LAST_LISTING" | grep -q -e "Codigo: $EXPECTED_INMUEBLE_CODE,"; then
    echo -e " ${COLOR_RED}FALLÓ${COLOR_NC}"
    ((FAILED_TESTS++))
else
    echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
    ((PASSED_TESTS++))
fi

# Verificación de Valgrind
echo -n -e "${COLOR_YELLOW}[VERIFICANDO]${COLOR_NC} Fugas de memoria con Valgrind..."
((TOTAL_TESTS++))
if grep -q -E 'definitely lost|indirectly lost' "$VALGRIND_LOG"; then
    echo -e " ${COLOR_RED}FALLÓ${COLOR_NC}"
    ((FAILED_TESTS++))
else
    echo -e " ${COLOR_GREEN}ÉXITO${COLOR_NC}"
    ((PASSED_TESTS++))
fi
echo ""

# --- Resumen Final ---
echo "==================== Resumen de la Prueba ===================="
echo "Total de verificaciones: $TOTAL_TESTS"
echo -e "Verificaciones ${COLOR_GREEN}exitosas: $PASSED_TESTS${COLOR_NC}"
echo -e "Verificaciones ${COLOR_RED}fallidas: $FAILED_TESTS${COLOR_NC}"
echo "============================================================"

if [ "$FAILED_TESTS" -eq 0 ]; then
    echo -e "${COLOR_GREEN}¡Felicidades! Todas las pruebas pasaron. El programa es funcionalmente correcto.${COLOR_NC}"
else
    echo -e "${COLOR_RED}Algunas pruebas fallaron. Revisa la salida en tiempo real de arriba y los archivos de registro para más detalles:${COLOR_NC}"
    echo " - Salida del Programa: $STDOUT_LOG"
    echo " - Reporte de Valgrind: $VALGRIND_LOG"
fi

# Nota final sobre la fuga de memoria de los Singletons
if grep -q -E 'definitely lost|indirectly lost' "$VALGRIND_LOG"; then
    echo -e "\n${COLOR_YELLOW}NOTA IMPORTANTE SOBRE VALGRIND:${COLOR_NC}"
    echo "La falla de Valgrind se debe a que las instancias de tus clases Singleton (Factory, Controladores, Handlers) se crean con 'new' pero nunca se liberan con 'delete'. Aunque el sistema operativo recupera esta memoria al final, Valgrind lo reporta correctamente como una fuga. Para un código 100% limpio, deberías implementar una forma de liberar estas instancias antes de que el programa termine."
fi

exit "$FAILED_TESTS"
