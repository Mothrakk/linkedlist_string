#include "str\str.h"

int main(void) {
    string *str = build("wazup my friend");
    print(str, '\n'); // "wazup my friend"

    append(" lol xd ebis", str);
    print(str, '\n'); // "wazup my friend lol xd ebis"

    cut_tail(2, str);
    print(str, '\n'); // "wazup my friend lol xd eb"

    destroy_string(str);


    return 0;
}