PROJECT(repasoC)

set(basic_file_dir ${CMAKE_CURRENT_SOURCE_DIR}/basic_file_io)
set(centroid_dir ${CMAKE_CURRENT_SOURCE_DIR}/centroid_from_file)
set(file_dir ${CMAKE_CURRENT_SOURCE_DIR}/file_simple_protocol)
set(point_dir ${CMAKE_CURRENT_SOURCE_DIR}/point_malloc)
set(matrix_dir ${CMAKE_CURRENT_SOURCE_DIR}/read_matrix)

ADD_EXECUTABLE(basic_file_io ${basic_file_dir}/file_io.c)
#ADD_EXECUTABLE(centroid ${centroid_dir}/centroide.c)
#ADD_EXECUTABLE(file ${file_dir}/file_simple_prot_main.c)
#ADD_EXECUTABLE(point ${point_dir}/point.c)
#ADD_EXECUTABLE(matrix ${matrix_dir}/read_matrix.c)