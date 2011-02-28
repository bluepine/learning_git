#!/bin/bash
set -x
javac -sourcepath src -d build/classes src/oata/HelloWorld.java
java -cp build/classes oata.HelloWorld
