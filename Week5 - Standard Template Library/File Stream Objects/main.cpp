//* FILE STREAM OBJECTS
/*
? Class Hierarchy
_ Input-Output stream class hierachy supports streaming to and form the standard console devices,
files and string streams. The base class for this hierarchy is ios_base. Defines components that 
are independent of direction of the stream.

    * ios Class Hierarchy:
    _ ios class is the instance of basic_ios template for streams for type char. istream and ostream
    are abstract classes derived from ios class.

    * ios_base class:
    _ Shared by both hierarchies holds formatting imformataion, stream state flags, stream open mode
    flags and the stream seeking direction flag

    * basic_ios Templeate:
    _ Adds the fill character and holds the current state. Its member functions provide access to state flags

    * ios Classes:
    _ Defines the base class for narrow character (char) input and output

    * wios Clas:
    _ Defines the base class for wide character (wchar_t) input and output

? File Objects
_ Manage the transfer of data between program memory and files through buffers.
It can connect to a stream if either:
    + Text mode: The stream consists of character interpreted using an encoding sequence and has a record
    structure with a terminator that identifies the end of each record
    + Binary mode: The stream consists of characters without any interpretation or structure 

? Close a Connection
_ The destructor for a file object flushes the buffer and closes the file when the object goes out of scope.


? Binary Access
_ Binary access transfers data to and from memory without any formatting; there is no conversion, insertion, or extraction 
of record or field separators. Binary access lets us save the image of the contents of memory without any loss of information.
*/