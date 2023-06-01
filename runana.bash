#!/bin/bash

#Analyse list of root files 
rootFilesList="./rootFileList.dat"
outHistF="./hist.root"

#Or analyse single root file 
inRootFiles="../simtel_data/gamma/log_short_root/gamma.root"
outHistSingleF="./hist_gamma.root"

make -f Makefileana clean; make -f Makefileana runana;

function printHelp {
    echo " --> ERROR in input arguments "
    echo " [0] -d    : single root file"
    echo " [0] --g   : gamma"
    echo " [0] --gd  : gamma_diffuse"
    echo " [0] --el  : electron"
    echo " [0] --pr  : proton"
    echo " [0] --all : all"
    echo " [0] -l    : list of root files"
    echo " [0] -h    : print help"
}

if [ $# -eq 0 ] 
then    
    printHelp
else
    if [ "$1" = "-d" ]; then
	./runana 1 $inRootFiles $outHistSingleF
    elif [ "$1" = "--g" ]; then
	./runana 1 ../simtel_data/gamma/log_short_root/gamma.root ./hist_gamma.root
    elif [ "$1" = "--gd" ]; then
	./runana 1 ../simtel_data/gamma_diffuse/log_short_root/gamma_diffuse.root ./hist_gamma_diffuse.root
    elif [ "$1" = "--el" ]; then
	./runana 1 ../simtel_data/electron/log_short_root/electron.root ./hist_electron.root
    elif [ "$1" = "--pr" ]; then
	./runana 1 ../simtel_data/proton/log_short_root/proton.root ./hist_proton.root
    elif [ "$1" = "--all" ]; then
	./runana 1 ../simtel_data/gamma/log_short_root/gamma.root ./hist_gamma.root
	./runana 1 ../simtel_data/gamma_diffuse/log_short_root/gamma_diffuse.root ./hist_gamma_diffuse.root
	./runana 1 ../simtel_data/electron/log_short_root/electron.root ./hist_electron.root
	./runana 1 ../simtel_data/proton/log_short_root/proton.root ./hist_proton.root
    elif [ "$1" = "-l" ]; then
	./runana 0 $rootFilesList $outHistF
        printHelp
    elif [ "$1" = "-h" ]; then
        printHelp
    else
        printHelp
    fi
fi

#espeak "I have done"
