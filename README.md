---
documentclass: physycomen
title:  "ScriptLogCleaner"
author: "Sinigardi"
---

<a href="http://www.physycom.unibo.it"> 
<div class="image">
<img src="https://cdn.rawgit.com/physycom/templates/697b327d/logo_unibo.png" width="90" height="90" alt="© Physics of Complex Systems Laboratory - Physics and Astronomy Department - University of Bologna"> 
</div>
</a>
<a href="https://travis-ci.org/physycom/ScriptLogCleaner"> 
<div class="image">
<img src="https://travis-ci.org/physycom/ScriptLogCleaner.svg?branch=master" width="90" height="20" alt="Build Status"> 
</div>
</a>
<a href="https://ci.appveyor.com/project/cenit/ScriptLogCleaner"> 
<div class="image">
<img src="https://ci.appveyor.com/api/projects/status/4h5byax58ie5yrbv?svg=true" width="90" height="20" alt="Build Status"> 
</div>
</a>

### Purpose
This tool has been written in order to clean up the logs saved from a `ssh` session.

### Installation
**CMake**, a **C++11** compatible compiler and **boost** libraries are required. To build the executable, clone the repo and then type  
```
mkdir build ; cd build ; cmake .. ; cmake --build . --target install
```
With CMake you can also deploy projects for the most common IDEs.  

