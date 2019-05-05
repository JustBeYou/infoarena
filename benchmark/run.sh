#!/bin/bash

echo "scanf: "
make scanf && time ./scanf
echo -e "\ncin: "
make cin && time ./cin
echo -e "\ncin without sync: "
make cin_sync && time ./cin_sync
echo -e "\ncin without sync and tie: "
make cin_sync_tie && time ./cin_sync_tie
