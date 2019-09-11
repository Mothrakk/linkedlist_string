#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

string* make_head() {
    string *str = (string*)malloc(sizeof(string));
    str->first = NULL;
    str->last = NULL;
    str->len = 0;
    return str;
}

void string_update_first(string *str, element *ptr) {
    while (ptr->prev != NULL) {
        ptr = ptr->prev;
    }
    str->first = ptr;
}

void string_update_last(string *str, element *ptr) {
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    str->last = ptr;
}

void string_update_len(string *str) {
    element *ptr = str->first;
    str->len = 0;
    while (ptr != NULL) {
        str->len++;
        ptr = ptr->next;
    }
}

void string_update(string *str, element *ptr) {
    string_update_first(str, ptr);
    string_update_last(str, ptr);
    string_update_len(str);
}

element* build_next(const char str[], int i, element *prev) {
    if (!str[i]) { return NULL; }
    element *this = (element*)malloc(sizeof(element));
    this->c = str[i];
    this->prev = prev;
    this->next = build_next(str, i + 1, this);
    return this;
}

string* build(const char str[]) {
    string *head = make_head();
    element *first = build_next(str, 0, NULL);
    head->first = first;
    head->len = strlen(str);
    string_update_last(head, first);
    return head;
}

void cut_tail(int amount, string *str) {
    if (amount <= str->len && amount > 0) {
        str->len -= amount;
        element *ptr = str->last;
        while (amount--) {
            ptr = ptr->prev;
        }
        destroy_element_chain(ptr->next);
        ptr->next = NULL;
        str->last = ptr;
    }
}

void append(const char str[], string *s) {
    s->last->next = build_next(str, 0, s->last);
    string_update_last(s, s->last);
    s->len += strlen(str);
}

void print(string *str, char end) {
    element *ptr = str->first;
    while (ptr != NULL) {
        putchar(ptr->c);
        ptr = ptr->next;
    }
    putchar(end);
}

void destroy_element_chain(element *ptr) {
    element *temp;
    while (ptr != NULL) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

void destroy_string(string *str) {
    destroy_element_chain(str->first);
    free(str);
}