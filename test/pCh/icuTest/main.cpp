#include <stdio.h>
#include <dlfcn.h> 
#include "unicode/utf16.h"
#include "unicode/utypes.h"
#include "unicode/uchar.h"
#include "unicode/locid.h"
#include "unicode/ustring.h"
#include "unicode/ucnv.h"
#include "unicode/unistr.h"
#include "unicode/utypes.h"
#include "unicode/ustring.h"
#include "unicode/alphaindex.h"
#include "unicode/locid.h"
#include "unicode/uloc.h"
using namespace icu;


char U_ICUDATA_ENTRY_POINT [65536];
static UConverter *cnv=NULL;
//void printUString(const char *announce, const UChar *s, int32_t length);
//void printUnicodeString(const char *announce, const UnicodeString &s); 
void demo_C_Unicode_strings();

int main(int args, char ** argv)
{
    UErrorCode status;
    AlphabeticIndex *index =  new AlphabeticIndex(Locale::getTraditionalChinese(), status);
    
    printf("hello world\n");
    return 0;
}

//void printUnicodeString(const char *announce, const UnicodeString &s) {
//    static char out[200];
//    int32_t i, length;
//
//    // output the string, converted to the platform encoding
//
//    // Note for Windows: The "platform encoding" defaults to the "ANSI codepage",
//    // which is different from the "OEM codepage" in the console window.
//    // However, if you pipe the output into a file and look at it with Notepad
//    // or similar, then "ANSI" characters will show correctly.
//    // Production code should be aware of what encoding is required,
//    // and use a UConverter or at least a charset name explicitly.
//    out[s.extract(0, 99, out)]=0;
//    printf("%s%s {", announce, out);
//
//    // output the code units (not code points)
//    length=s.length();
//    for(i=0; i<length; ++i) {
//        printf(" %04x", s.charAt(i));
//    }
//    printf(" }\n");
//}
//
//void demo_C_Unicode_strings() {
//    printf("\n* demo_C_Unicode_strings() --------- ***\n\n");
//
//    static const UChar text[]={ 0x41, 0x42, 0x43, 0 };          /* "ABC" */
//    static const UChar appendText[]={ 0x61, 0x62, 0x63, 0 };    /* "abc" */
//    static const UChar cmpText[]={ 0x61, 0x53, 0x73, 0x43, 0 }; /* "aSsC" */
//    UChar buffer[32];
//    int32_t compare;
//    int32_t length=u_strlen(text); /* length=3 */
//
//    /* simple ANSI C-style functions */
//    buffer[0]=0;                    /* empty, NUL-terminated string */
//    u_strncat(buffer, text, 1);     /* append just n=1 character ('A') */
//    u_strcat(buffer, appendText);   /* buffer=="Aabc" */
//    length=u_strlen(buffer);        /* length=4 */
//    printUString("should be \"Aabc\": ", buffer, -1);
//
//    /* bitwise comparing buffer with text */
//    compare=u_strcmp(buffer, text);
//    if(compare<=0) {
//        printf("String comparison error, expected \"Aabc\" > \"ABC\"\n");
//    }
//
//    /* Build "A<sharp s>C" in the buffer... */
//    u_strcpy(buffer, text);
//    buffer[1]=0xdf; /* sharp s, case-compares equal to "ss" */
//    printUString("should be \"A<sharp s>C\": ", buffer, -1);
//
//    /* Compare two strings case-insensitively using full case folding */
//    compare=u_strcasecmp(buffer, cmpText, U_FOLD_CASE_DEFAULT);
//    if(compare!=0) {
//        printf("String case insensitive comparison error, expected \"AbC\" to be equal to \"ABC\"\n");
//    }
//}
//
//void printUString(const char *announce, const UChar *s, int32_t length) {
//    static char out[200];
//    UChar32 c;
//    int32_t i;
//    UErrorCode errorCode=U_ZERO_ERROR;
//
//    /*
//     * Convert to the "platform encoding". See notes in printUnicodeString().
//     * ucnv_fromUChars(), like most ICU APIs understands length==-1
//     * to mean that the string is NUL-terminated.
//     */
//    ucnv_fromUChars(cnv, out, sizeof(out), s, length, &errorCode);
//    if(U_FAILURE(errorCode) || errorCode==U_STRING_NOT_TERMINATED_WARNING) {
//        printf("%sproblem converting string from Unicode: %s\n", announce, u_errorName(errorCode));
//        return;
//    }
//
//    printf("%s%s {", announce, out);
//
//    /* output the code points (not code units) */
//    if(length>=0) {
//        /* s is not NUL-terminated */
//        for(i=0; i<length; /* U16_NEXT post-increments */) {
//            U16_NEXT(s, i, length, c);
//            printf(" %04x", c);
//        }
//    } else {
//        /* s is NUL-terminated */
//        for(i=0; /* condition in loop body */; /* U16_NEXT post-increments */) {
//            U16_NEXT(s, i, length, c);
//            if(c==0) {
//                break;
//            }
//            printf(" %04x", c);
//        }
//    }
//    printf(" }\n");
//}
