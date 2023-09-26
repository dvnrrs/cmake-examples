cmake_minimum_required(VERSION 3.24)

project(3-variable-scopes)

# Normal variables cannot be overridden
set(NORMAL_VARIABLE "I'm a normal variable")
message(WARNING "NORMAL_VARIABLE = ${NORMAL_VARIABLE}")

# Cache variables can be overridden (first setter wins; see also ccmake!)
set(CACHE_VARIABLE "I'm a cache variable" CACHE STRING "This is the documentation for CACHE_VARIABLE")
message(WARNING "CACHE_VARIABLE = ${CACHE_VARIABLE}")

# Subdirectory will inherit all our variables, but we won't see any normal
# variables it sets unless it uses PARENT_SCOPE. We will see cache variables.
add_subdirectory(sub)
message(WARNING "SUB_VARIABLE_NORMAL_SCOPE = ${SUB_VARIABLE_NORMAL_SCOPE}")
message(WARNING "SUB_VARIABLE_PARENT_SCOPE = ${SUB_VARIABLE_PARENT_SCOPE}")

function(myfunc)
    set(VARIABLE_SET_BY_FUNC "you don't see me")
    set(VARIABLE_SET_BY_FUNC_PARENT_SCOPE "you see me!" PARENT_SCOPE)
endfunction()

macro(mymacro)
    set(VARIABLE_SET_BY_MACRO "you see me!")
endmacro()

myfunc()
message(WARNING "VARIABLE_SET_BY_FUNC = ${VARIABLE_SET_BY_FUNC}")
message(WARNING "VARIABLE_SET_BY_FUNC_PARENT_SCOPE = ${VARIABLE_SET_BY_FUNC_PARENT_SCOPE}")

mymacro()
message(WARNING "VARIABLE_SET_BY_MACRO = ${VARIABLE_SET_BY_MACRO}")
