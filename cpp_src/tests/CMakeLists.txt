set(TEST_SOURCES
    main_test.cpp
)

add_executable(unit_tests ${TEST_SOURCES})

target_link_libraries(unit_tests PRIVATE 

)

add_test(NAME CoreTest COMMAND unit_tests)
