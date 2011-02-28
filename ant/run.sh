#!/bin/bash
set -x
echo Main-Class: oata.HelloWorld>myManifest
mkdir -p build/jar
jar cfm build/jar/HelloWorld.jar myManifest -C build/classes .
java -jar build/jar/HelloWorld.jar
