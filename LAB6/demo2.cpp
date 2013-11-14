#include <iostream>
using namespace std;

#include "MyString.h"

void print_in_quotes(const MyString& s, const char *b);

int main()
{
    const char *nineteen_chars = "0123456789012345678";
    const char *twenty_chars = "01234567890123456789";

    cout << "demonstrating ctors ... \n";
    MyString s1;
    cout << "   s1 is ";
    print_in_quotes(s1, "");
    cout << "   s1.length() is " << s1.length()
    << " (expected 0)\n";

    MyString s2("foo");
    cout << "   s2 is ";
    print_in_quotes(s2, "foo");
    cout << "   s2.length() is " << s2.length()
    << " (expected 3)\n";

    MyString s3(nineteen_chars);
    cout << "   s3 is ";          // typo in orginal code corrected
    print_in_quotes(s3, nineteen_chars);
    cout << "   s3.length() is " << s3.length()
    << " (expected 19)\n";

    MyString s4(twenty_chars);
    cout << "   s4 is ";
    print_in_quotes(s4, nineteen_chars);
    cout << "   s4.length() is " << s4.length()
    << " (expected 19)\n";

    cout << "... end of ctor demonstration.\n\n";

    cout << "Demonstrating at by printing s4 one char at a time ...\n";
    cout << "   characters in s4 are: ";
    for (int i = 0; i < s4.length(); i++)
        cout << s4.at(i);
    cout << "\n... end of at demonstration.\n\n";
    
//     End of code originally supplied to students; beginning of code
//     added to demonstrate functions coded to complete the exercise.
    
    cout << "Demonstrating equals(const char *) ...\n";
    MyString s5("abc");
    cout << "   s5 is \"" << s5.c_str() << "\"\n";
    cout << "   s5.equals(\"abc\") is " <<  s5.equals("abc") << ".\n";
    cout << "   s5.equals(\"bbc\") is " <<  s5.equals("bbc") << ".\n";
    cout << "   s5.equals(\"ab\") is " <<  s5.equals("ab") << ".\n";
    cout << "   s5.equals(\"abd\") is " <<  s5.equals("abd") << ".\n";
    cout << "   s5.equals(\"abcd\") is " <<  s5.equals("abcd") << ".\n";

    cout << "\nDemonstrating equals(const MyString&) ...\n";
    cout << "   s5 is \"" << s5.c_str() << "\"\n";
    MyString s6("abc");
    cout << "   s6 is \"" << s6.c_str() << "\"\n";
    MyString s7("bbc");
    cout << "   s7 is \"" << s7.c_str() << "\"\n";
    MyString s8("ab");
    cout << "   s8 is \"" << s8.c_str() << "\"\n";
    MyString s9("abd");
    cout << "   s9 is \"" << s9.c_str() << "\"\n";
    MyString s10("abcd");
    cout << "   s10 is \"" << s10.c_str() << "\"\n";
    cout << "   s5.equals(s6) is " <<  s5.equals(s6) << ".\n";
    cout << "   s5.equals(s7) is " <<  s5.equals(s7) << ".\n";
    cout << "   s5.equals(s8) is " <<  s5.equals(s8) << ".\n";
    cout << "   s5.equals(s9) is " <<  s5.equals(s9) << ".\n";
    cout << "   s5.equals(s10) is " <<  s5.equals(s10) << ".\n";

    cout << "\nDemonstrating set_char_at ...\n";
    s5.set_char_at(0, 'x');
    cout << "   s5 is ";
    print_in_quotes(s5, "xbc");
    s5.set_char_at(2, 'y');
    cout << "   s5 is ";
    print_in_quotes(s5, "xby");

    cout << "\nDemonstrating append(const char *) ...\n";
    MyString s11("abcdefghij");
    s11.append("");
    cout << "   s11 is ";
    print_in_quotes(s11, "abcdefghij");
    cout << "   s11.length() is " << s11.length() << " (expected 10)\n";
    s11.append("abcde");
    cout << "   s11 is ";
    print_in_quotes(s11, "abcdefghijabcde");
    cout << "   s11.length() is " << s11.length() << " (expected 15)\n";
    s11.append("fghij");          // no room for final 'j' in s11
    cout << "   s11 is ";
    print_in_quotes(s11, "abcdefghijabcdefghi");
    cout << "   s11.length() is " << s11.length() << " (expected 19)\n";


    cout << "\nDemonstrating append(const MyString&) ...\n";
    MyString s12("abcdefghij");
    MyString empty;
    MyString abcde("abcde");
    MyString fghij("fghij");
    s12.append(empty);
    cout << "   s12 is ";
    print_in_quotes(s12, "abcdefghij");
    cout << "   s12.length() is " << s12.length() << " (expected 10)\n";
    s12.append(abcde);
    cout << "   s12 is ";
    print_in_quotes(s12, "abcdefghijabcde");
    cout << "   s12.length() is " << s12.length() << " (expected 15)\n";
    s12.append(fghij);          // no room for final 'j' in s12
    cout << "   s12 is ";
    print_in_quotes(s12, "abcdefghijabcdefghi");
    cout << "   s12.length() is " << s12.length() << " (expected 19)\n";

    cout << "\nDemonstrating truncate ...\n";
    MyString s13("abcdefghij");
    s13.truncate(10);
    cout << "   s13 is ";
    print_in_quotes(s13, "abcdefghij");
    cout << "   s13.length() is " << s13.length() << " (expected 10)\n";
    s13.truncate(8);
    cout << "   s13 is ";
    print_in_quotes(s13, "abcdefgh");
    cout << "   s13.length() is " << s13.length() << " (expected 8)\n";
    s13.truncate(0);
    cout << "   s13 is ";
    print_in_quotes(s13, "");
    cout << "   s13.length() is " << s13.length() << " (expected 0)\n";

    return 0;
}

void print_in_quotes(const MyString& s, const char *b)
{
    cout << '"' << s.c_str() << '"';
    cout << " (expected \"" << b << "\")\n";
}

