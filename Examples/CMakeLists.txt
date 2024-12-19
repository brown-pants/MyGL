set(examples_folder Examples)

if(NOT TARGET Lighting)
    add_subdirectory(Lighting)
    set_target_properties(Lighting PROPERTIES FOLDER ${example_folder}/Lighting)
endif()