#Cmake find for Asset Import library
#Original found here https://github.com/assimp/assimp/blob/master/cmake-modules/Findassimp.cmake
#modified by Brian McDonald on 2/6/16 to work with Mac OS(Assimp installed from MacPorts)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(ASSIMP_ARCHITECTURE "64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(ASSIMP_ARCHITECTURE "32")
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

if(WIN32)
	#set(ASSIMP_ROOT_DIR CACHE PATH "ASSIMP root directory")

	# Find path of each library
	find_path(ASSIMP_INCLUDE_DIR
		NAMES
			assimp/anim.h
		HINTS
			$ENV{ASSIMP_ROOT_DIR}/include
	)

	if(MSVC12)
		set(ASSIMP_MSVC_VERSION "vc120")
	elseif(MSVC14)
		set(ASSIMP_MSVC_VERSION "vc140")
	endif(MSVC12)



	if(MSVC12 OR MSVC14)

		find_library(ASSIMP_LIBRARIES
				assimp-${ASSIMP_MSVC_VERSION}-mt.lib
				PATHS $ENV{ASSIMP_ROOT_DIR}/lib)
	endif()

else(WIN32)

	find_path(
	  ASSIMP_INCLUDE_DIR
	  NAMES postprocess.h scene.h version.h config.h cimport.h
	  PATHS
		/usr/include/assimp
		/opt/local/include/assimp
		/usr/local/include/assimp
	)

	find_library(
	  ASSIMP_LIBRARIES
	  NAMES libassimp
	  PATHS
		/usr/lib/
		/opt/local/lib/
		/usr/local/lib/
	)

	if (ASSIMP_INCLUDE_DIR AND ASSIMP_LIBRARIES)
	  SET(assimp_FOUND TRUE)
	ENDIF (ASSIMP_INCLUDE_DIR AND ASSIMP_LIBRARIES)

	if (assimp_FOUND)
	  if (NOT assimp_FIND_QUIETLY)
		message(STATUS "Found asset importer library: ${assimp_LIBRARIES}")
	  endif (NOT assimp_FIND_QUIETLY)
	else (assimp_FOUND)
	  if (assimp_FIND_REQUIRED)
		message(FATAL_ERROR "Could not find asset importer library")
	  endif (assimp_FIND_REQUIRED)
	endif (assimp_FOUND)

endif(WIN32)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Assimp DEFAULT_MSG ASSIMP_INCLUDE_DIR ASSIMP_LIBRARIES)
mark_as_advanced(ASSIMP_INCLUDE_DIR ASSIMP_LIBRARIES)
