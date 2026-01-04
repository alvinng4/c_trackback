execute_process(
    COMMAND ${TEST_PROG}
    OUTPUT_VARIABLE TEST_OUTPUT
    ERROR_VARIABLE TEST_OUTPUT
    RESULT_VARIABLE TEST_RESULT
)

message("${TEST_OUTPUT}")

# Determine Success
# The output contains "Traceback" (Even if it crashed)
if(TEST_OUTPUT MATCHES "Traceback")
    message(STATUS "Traceback detected. Test Passed.")
# The program ran successfully (Exit code 0)
elseif(TEST_RESULT EQUAL 0)
    message(STATUS "Clean exit. Test Passed.")
else()
# Fail: It crashed AND didn't print a Traceback
    message(FATAL_ERROR "Test Failed: Process crashed (Code: ${TEST_RESULT}) and no 'Traceback' found.")
endif()
