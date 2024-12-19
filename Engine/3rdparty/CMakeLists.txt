set(third_party_folder 3rdparty)

#build glfw
if(NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
    set_target_properties(glfw PROPERTIES FOLDER ${third_party_folder}/glfw)
	set_target_properties(update_mappings PROPERTIES FOLDER ${third_party_folder}/glfw)
endif()

#build imgui
if(NOT TARGET imgui)
    add_subdirectory(imgui)
    set_target_properties(imgui PROPERTIES FLODER ${third_party_folder}/imgui)
endif()