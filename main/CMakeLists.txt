include(../cmake-bin2h/bin2h.cmake)

set(HEADER_FILE "../main/http_content.h")
bin2h(SOURCE_FILE "../html/index.html" HEADER_FILE ${HEADER_FILE} VARIABLE_NAME "index" NULL_TERMINATE)
bin2h(SOURCE_FILE "../html/command.json" HEADER_FILE ${HEADER_FILE} VARIABLE_NAME "command" APPEND NULL_TERMINATE)
file(APPEND ${HEADER_FILE} "\n")

idf_component_register(SRCS "main.c" "http.c" "wifi.c"
                    INCLUDE_DIRS "")
