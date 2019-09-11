#ifndef STR
#define STR

typedef struct string string;
typedef struct element element;

struct element {
    char c;
    element *prev, *next;
};

struct string {
    int len;
    element *first, *last;
};

string* make_head();
void string_update_first(string *str, element *ptr);
void string_update_last(string *str, element *ptr);
void string_update_len(string *str);
void string_update(string *str, element *ptr);

element* build_next(const char str[], int i, element *prev);
string* build(const char str[]);

void cut_tail(int amount, string *str);
void append(const char str[], string *s);
void print(string *str, char end);

void destroy_element_chain(element *ptr);
void destroy_string(string *str);

#endif