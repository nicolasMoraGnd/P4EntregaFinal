#!/bin/bash

# --- Configuration ---
EXEC="./main"
LOG_FILE="test_output.log"
EXPECTED_INMUEBLE_CODE=9  # Assuming 8 existing + 1 new. Adjust if needed.
EXPECTED_PUBLICACION_CODE=18 # Assuming 17 existing + 1 new. Adjust if needed.

# --- Helper Functions ---
function run_step {
    echo "--- Running Step: $1 ---" | tee -a "$LOG_FILE"
    echo "$2" | "$EXEC" 2>&1 | tee -a "$LOG_FILE"
    if [ "${PIPESTATUS[1]}" -ne 0 ]; then
        echo "ERROR: The program exited with an error during step '$1'." | tee -a "$LOG_FILE"
        exit 1
    fi
    echo "" | tee -a "$LOG_FILE" # Add a newline for readability
}

function check_output {
    local search_string="$1"
    local step_name="$2"
    if grep -q "$search_string" "$LOG_FILE"; then
        echo "SUCCESS: '$search_string' found for step '$step_name'." | tee -a "$LOG_FILE"
        return 0
    else
        echo "FAILURE: '$search_string' NOT found for step '$step_name'." | tee -a "$LOG_FILE"
        return 1
    fi
}

function assert_success {
    if [ $? -ne 0 ]; then
        echo "TEST FAILED: Previous step did not pass validation." | tee -a "$LOG_FILE"
        exit 1
    fi
}

# --- Main Test Execution ---
echo "--- Starting Comprehensive System Validation Test ---" > "$LOG_FILE"
echo "Log file: $LOG_FILE" | tee -a "$LOG_FILE"

# 1. Compile the project
echo "--- Compiling Project ---" | tee -a "$LOG_FILE"
make clean &>> "$LOG_FILE" # Clean first
make all &>> "$LOG_FILE"   # Then compile
if [ $? -ne 0 ]; then
    echo "ERROR: Compilation failed. Please fix compilation errors before running tests." | tee -a "$LOG_FILE"
    exit 1
fi
echo "Compilation successful." | tee -a "$LOG_FILE"

# 2. Initialize System and Load Basic Data
# Note: Input for date setting will loop the menu. We need to send all inputs at once.
run_step "Set Date and Load Data" "$(cat <<EOF
11
20
6
2024
9
0
EOF
)"
check_output "fecha actual: 20/6/2024" "Set Date"
assert_success

# 3. Verify User Creation (Clients, Owners, Inmobiliarias) and Owner Properties
run_step "Create Test Owner and Property" "$(cat <<EOF
1
2
test_owner
securepass
Test
test@example.com
112233445566
099111222
1
1
Calle Ficticia 123
123
100
2010
0
2
0
0
EOF
)"
check_output "test_owner" "Test Owner Creation" # Check if nickname appears in output (e.g., via menu list before exiting)
assert_success

# Verify property listing
run_step "List Inmuebles to find new property" "$(cat <<EOF
4
0
EOF
)" # Just list, don't delete
check_output "Codigo: $EXPECTED_INMUEBLE_CODE, direccion: Calle Ficticia 123, propietario: test_owner" "Property Listing"
assert_success


# 4. Verify Real Estate Representation and Administration
run_step "Create Test Inmobiliaria and Represent Owner" "$(cat <<EOF
1
1
test_inmo
inmopass
Test Inmobiliaria
info@testinmo.com
Av. Prueba 456
https://testinmo.com
23334444
1
test_owner
0
0
EOF
)"
check_output "test_inmo" "Test Inmobiliaria Creation"
assert_success

run_step "Administer Property" "$(cat <<EOF
8
test_inmo
$EXPECTED_INMUEBLE_CODE
0
EOF
)"
check_output "Codigo del inmueble a administrar:" "Property Administration" # Just check if the prompt appeared
assert_success

# 5. Verify Publication and Notification
run_step "Subscribe Client to Test Inmobiliaria" "$(cat <<EOF
5
luisito23
test_inmo
0
EOF
)"
check_output "Suscripcion realizada correctamente." "Subscription"
assert_success

run_step "Create Publication" "$(cat <<EOF
2
test_inmo
$EXPECTED_INMUEBLE_CODE
1
Casa de prueba en venta.
250000.0
0
EOF
)"
check_output "Precio:" "Publication Creation" # Check if the last prompt appeared
assert_success

# Consult notifications (luisito23)
run_step "Consult Notifications for luisito23" "$(cat <<EOF
6
luisito23
0
EOF
)"
check_output "- Inmobiliaria: test_inmo, Codigo Inmueble: $EXPECTED_INMUEBLE_CODE, Tipo Publicacion: Venta, Texto: Casa de prueba en venta." "Notification Check"
assert_success

# 6. Verify Publication Listing and Detail
run_step "Consult Publications (filtered)" "$(cat <<EOF
3
1
200000.0
300000.0
1
1
$EXPECTED_PUBLICACION_CODE
0
EOF
)"
check_output "Codigo: $EXPECTED_PUBLICACION_CODE, fecha: 20/6/2024, texto: Casa de prueba en venta., precio: 250000, inmobiliaria: Test Inmobiliaria" "Filtered Publication Listing"
assert_success
check_output "Codigo: $EXPECTED_PUBLICACION_CODE, direccion: Calle Ficticia 123, nro. puerta: 123, superficie: 100 m2, construccion: 2010, PH: No, Tipo de techo: Plano" "Publication Detail"
assert_success


# 7. Verify Unsubscribe Functionality
run_step "Unsubscribe Client from Test Inmobiliaria" "$(cat <<EOF
7
luisito23
test_inmo
0
EOF
)"
check_output "Desuscripcion realizada correctamente." "Unsubscription"
assert_success


# 8. Verify Inmueble Deletion
run_step "Delete Test Property" "$(cat <<EOF
4
$EXPECTED_INMUEBLE_CODE
1
0
EOF
)"
check_output "Desea eliminar?: (1: Si, 0: No)" "Property Deletion Confirmation"
assert_success

run_step "Verify Property Deletion by relisting" "$(cat <<EOF
4
0
EOF
)"
if grep -q "Codigo: $EXPECTED_INMUEBLE_CODE, direccion: Calle Ficticia 123, propietario: test_owner" "$LOG_FILE"; then
    echo "FAILURE: Deleted property still found in listing." | tee -a "$LOG_FILE"
    exit 1
else
    echo "SUCCESS: Deleted property not found in listing." | tee -a "$LOG_FILE"
fi

echo "--- All Tests Completed ---" | tee -a "$LOG_FILE"
echo "If no 'FAILURE' messages appeared above, the system seems to be functioning correctly." | tee -a "$LOG_FILE"

exit 0