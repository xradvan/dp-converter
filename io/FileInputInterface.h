#pragma once

#include "InputInterface.h"
#include "FileInterface.h"

class FileInputInterface : public InputInterface, public FileInterface {};
