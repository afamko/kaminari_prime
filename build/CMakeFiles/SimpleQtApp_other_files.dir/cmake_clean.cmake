file(REMOVE_RECURSE
  "qrc_myresources.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/SimpleQtApp_other_files.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
