#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#include "config/preferences.h"

void statuses_console_defaults_to_all(void **state)
{
    prefs_load();
    char *setting = prefs_get_string(PREF_STATUSES_CONSOLE);

    assert_non_null(setting);
    assert_string_equal("all", setting);

    prefs_close();
}

void statuses_chat_defaults_to_all(void **state)
{
    prefs_load();
    char *setting = prefs_get_string(PREF_STATUSES_CHAT);

    assert_non_null(setting);
    assert_string_equal("all", setting);

    prefs_close();
}

void statuses_muc_defaults_to_on(void **state)
{
    prefs_load();
    gboolean setting = prefs_get_boolean(PREF_STATUSES_MUC);

    assert_true(setting);

    prefs_close();
}