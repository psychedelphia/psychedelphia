ps_functions in C language


------ following <stdint.h> Data Types  ------(MUST) pollution :(
  
    *** i wish -> int8, uint8, int16, uint16, int32, uint32, int64, uint64, ... so on *** 
    ***           char, uchar, wchar, char16, char32                                  ***
    ***                                       float32, float64, float128              ***

int8_t = signed char [-127, +127] + all data types in this range(comment)

uint8_t = unsigned char [0, +255] + all data types in this range(comment)

int16_t = signed short [-32,767, +32,767] + all data types in this range(comment)

uint16_t = unsigned short [0, +65,535] + all data types in this range(comment)

int32_t = signed int [-2,147,483,647, + 2,147,483,647] + all data types in this range(comment)

uint32_t = unsigned int [0, +4,294,967,295] + all data types in this range(comment)

int64_t = signed long int [-9,223,372,036,854,775,807, +9,223,372,036,854,775,807]<br/>
          + all data types in this range(comment)

uint64_t = unsigned long int [0, +18,446,744,073,709,551,615] + all data types in this range(comment)

float32_t = float

float64_t = double

float128_t = long double

string = a set of characters( with '\0' - end of character set )

------ naming rules ------

it is up to you.(and me)

------ alias(typedef) ------(RECOMMENDED)

alias - comment needed

------ symbolic constant ------(RECOMMENDED)

UPPER_CASE - using alphabet rather than number

------ suffix of variable ------(RECOMMENDED)

_p(general), _ph(heap pointer) or _ptr(speciall) = pointer

------ suffix of function ------(REQUIRED)

_h = using heap memory(free() needed)

 
