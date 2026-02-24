#!/bin/bash

for folder in "$@"; do
  zip -r -q -9 archived.zip "$folder"
  echo "Zipped: $folder"
  rm -rf "$folder"
  echo "Removed: $folder"
done
