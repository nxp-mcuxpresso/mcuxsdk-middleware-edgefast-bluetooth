# Introduction

RT1170 works with two cores: M7 and M4, on which both all EdgeFast examples can run. However, all the EdgeFast examples in the release package are enabled on M7. Only the A2DP source example is enabled on M4.

EdgeFast projects for both the cores share the demo source files but with different project settings. Therefore, the examples can be migrated.

This document describes the steps to migrate EdgeFast examples from M7 to M4 with different toolchains. There are four main steps required. Additionally, you can also delete the function.

1.  Create an M4 project
2.  Rearrange source files
3.  Rearrange project files
4.  Adjust project settings
5.  Delete function

In this document, the peripheral\_ht example is used to demonstrate how to enable EdgeFast examples on M4 core with IAR and ARMGCC.

