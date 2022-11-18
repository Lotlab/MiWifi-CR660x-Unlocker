include(../cmake-bin2h/bin2h.cmake)

bin2h(SOURCE_FILE "../html/index.html" HEADER_FILE "../main/http_content.h" VARIABLE_NAME "index" NULL_TERMINATE)
bin2h(SOURCE_FILE "../html/command.json" HEADER_FILE "../main/http_content.h" VARIABLE_NAME "command" APPEND NULL_TERMINATE)

idf_component_register(SRCS "main.c" "http.c" "wifi.c"
                    INCLUDE_DIRS "")
