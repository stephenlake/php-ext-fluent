
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Fluent_Str) {

	ZEPHIR_REGISTER_CLASS(Fluent, Str, fluent, str, fluent_str_method_entry, 0);

	zend_declare_property_null(fluent_str_ce, SL("str"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(fluent_str_ce, SL("ignoreCase"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Fluent_Str, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *s = NULL, s_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &s);

	if (!s) {
		s = &s_sub;
		ZEPHIR_INIT_VAR(s);
		ZVAL_STRING(s, "");
	}


	zephir_update_property_zval(this_ptr, SL("str"), s);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("ignoreCase"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("ignoreCase"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Fluent_Str, startsWith) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *needle, needle_sub, length, _0, _6, _7, _8, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &needle);



	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(needle));
	zephir_read_property(&_0, this_ptr, SL("ignoreCase"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("str"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_strtolower(&_1$$3, &_2$$3);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &_1$$3, 0 , zephir_get_intval(&length), 0);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_fast_strtolower(&_5$$3, needle);
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_4$$3, &_5$$3));
	}
	zephir_read_property(&_6, this_ptr, SL("str"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_INIT_VAR(&_8);
	zephir_substr(&_8, &_6, 0 , zephir_get_intval(&length), 0);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_8, needle));

}

PHP_METHOD(Fluent_Str, endsWith) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *needle, needle_sub, length, _0, _5, _6, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &needle);



	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(needle));
	zephir_read_property(&_0, this_ptr, SL("ignoreCase"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("str"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_strtolower(&_1$$3, &_2$$3);
		zephir_negate(&length);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_substr(&_3$$3, &_1$$3, zephir_get_intval(&length), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, needle);
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_3$$3, &_4$$3));
	}
	if (ZEPHIR_IS_LONG(&length, 0)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_5, this_ptr, SL("str"), PH_NOISY_CC | PH_READONLY);
	zephir_negate(&length);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_5, zephir_get_intval(&length), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_6, needle));

}

PHP_METHOD(Fluent_Str, length) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("str"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_strlen_ev(&_0));

}

PHP_METHOD(Fluent_Str, splitBy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *separator = NULL, separator_sub, result, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &separator);

	if (!separator) {
		separator = &separator_sub;
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, " ");
	}


	zephir_read_property(&_0, this_ptr, SL("str"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&result);
	zephir_fast_explode(&result, separator, &_0, LONG_MAX);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Fluent_Str, split) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *separator = NULL, separator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &separator);

	if (!separator) {
		separator = &separator_sub;
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, " ");
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "splitby", NULL, 0, separator);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, explode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *separator = NULL, separator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &separator);

	if (!separator) {
		separator = &separator_sub;
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, " ");
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "splitby", NULL, 0, separator);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, ignoreCase) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, SL("ignoreCase"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("ignoreCase"), &__$false);
	}
	RETURN_THISW();

}

PHP_METHOD(Fluent_Str, ignoringCase) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "ignorecase", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str, str_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	object_init_ex(return_value, fluent_str_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, str);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, from) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str, str_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, str);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, of) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str, str_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, str);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, random) {

	zval _2$$3;
	zval stringA;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, size;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *length = NULL, length_sub, bytes, _1$$3, _3$$3, _4$$3, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&stringA);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length);

	if (!length) {
		length = &length_sub;
		ZEPHIR_INIT_VAR(length);
		ZVAL_LONG(length, 16);
	}


	ZEPHIR_INIT_VAR(&stringA);
	ZVAL_STRING(&stringA, "");
	size = 0;
	ZEPHIR_INIT_VAR(&bytes);
	ZVAL_LONG(&bytes, 0);
	while (1) {
		if (!(ZEPHIR_GT_LONG(length, zephir_fast_strlen_ev(&stringA)))) {
			break;
		}
		size = (zephir_get_numberval(length) - zephir_fast_strlen_ev(&stringA));
		ZEPHIR_CALL_FUNCTION(&bytes, "random_bytes", &_0, 2, length);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_create_array(&_2$$3, 3, 0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "+");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "=");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "base64_encode", &_5, 3, &bytes);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		zephir_fast_str_replace(&_1$$3, &_2$$3, &_3$$3, &_4$$3);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, size);
		ZEPHIR_INIT_NVAR(&_8$$3);
		zephir_substr(&_8$$3, &_1$$3, 0 , zephir_get_intval(&_7$$3), 0);
		zephir_concat_self(&stringA, &_8$$3);
	}
	RETURN_CTOR(&stringA);

}

PHP_METHOD(Fluent_Str, text) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__tostring", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, toString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__tostring", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fluent_Str, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "str");

}

