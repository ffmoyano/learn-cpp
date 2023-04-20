// EXTERNAL LINKAGE -> these identifiers can be used in multiple files
// External global variable definitions -> this variables are initialized here and can be used with this value in another file
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_y{ 1 };     // defines initialized const external global variable
extern constexpr int g_z{ 2 }; // defines initialized constexpr external global variable

// Forward declarations -> this variables are initialized in another file and are declared here with the value of the other file
extern int g_a;                // forward declaration for non-constant global variable
extern const int g_b;          // forward declaration for const global variable
// extern constexpr int g_c;      // not allowed: constexpr variables can't be forward declared

int main() {

}

// INTERNAL LINKAGE -> these identifiers can only be used in this file
// Internal global variables definitions:
static int g_d;          // defines non-initialized internal global variable (zero initialized by default)
static int g_e{ 1 };     // defines initialized internal global variable

const int g_f { 2 };     // defines initialized internal global const variable
constexpr int g_g { 3 }; // defines initialized internal global constexpr variable

// Internal function definitions:
static void foo() {};     // defines internal function