/* header guards: this ensure that a header file is implemented only once even if it is included in multiple files.
 * The first time is called HELLO is not defined yet, but second and posterior times is already defined and therefore
 * the code inside ifndef is not compiled.
 * This is not critical if we are only declaring functions and not defining them,
 * but, for example, user-defined types are normally defined in headers files, and those could end up defined multiple
 * times if not for
 * headers guards
 */

#ifndef HELLO
#define HELLO

void hello();  // we should only declare functions here, don't define their body

#endif