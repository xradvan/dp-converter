/**
 *@file FileOutputInterface.h
 *@author Bc. Peter Radvan
 *@brief File output interface
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "OutputInterface.h"
#include "FileInterface.h"

class FileOutputInterface : public OutputInterface, public FileInterface {};
