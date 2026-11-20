if(LLVM_VERSION_MAJOR LESS 16)
  # LLVM 14 and 15 still provide the CFL analyses in LLVMAnalysis.
  return()
endif()

file(GLOB_RECURSE LLVM_AA_SRC *.h *.cpp)
target_sources(phasar_llvm_pointer PRIVATE ${LLVM_AA_SRC})
