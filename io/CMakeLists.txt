add_library(IO
	# input
	DefaultInput.cpp
	ObserverInput.cpp
	MockInput.cpp
	MQInput.cpp
	SourceInput.cpp

	# output
	DefaultOutput.cpp
	ComparableOutput.cpp
	MQOutput.cpp
	ObservableOutput.cpp
	RawOutput.cpp
	SourceOutput.cpp
)
