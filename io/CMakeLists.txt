add_library(IO
	# input
	DefaultFileInput.cpp
	ObserverInput.cpp
	MockInput.cpp
	MQFileInput.cpp
	SourceInput.cpp

	# output
	DefaultFileOutput.cpp
	ComparableOutput.cpp
	MQFileOutput.cpp
	ObservableOutput.cpp
	RawOutput.cpp
	SourceOutput.cpp
)
