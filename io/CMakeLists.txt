add_library(IO
	# input
	DefaultInput.cpp
	ObserverInput.cpp
	MockInput.cpp
	MQInput.cpp

	# output
	#DefaultOutput.cpp
	ComparableOutput.cpp
	#MQOutput.cpp
	ObservableOutput.cpp
	RawOutput.cpp
)
