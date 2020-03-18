
extern zend_class_entry *fluent_str_ce;

ZEPHIR_INIT_CLASS(Fluent_Str);

PHP_METHOD(Fluent_Str, __construct);
PHP_METHOD(Fluent_Str, startsWith);
PHP_METHOD(Fluent_Str, endsWith);
PHP_METHOD(Fluent_Str, length);
PHP_METHOD(Fluent_Str, splitBy);
PHP_METHOD(Fluent_Str, split);
PHP_METHOD(Fluent_Str, explode);
PHP_METHOD(Fluent_Str, ignoreCase);
PHP_METHOD(Fluent_Str, ignoringCase);
PHP_METHOD(Fluent_Str, create);
PHP_METHOD(Fluent_Str, from);
PHP_METHOD(Fluent_Str, of);
PHP_METHOD(Fluent_Str, random);
PHP_METHOD(Fluent_Str, text);
PHP_METHOD(Fluent_Str, toString);
PHP_METHOD(Fluent_Str, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_startswith, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_endswith, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_splitby, 0, 0, 0)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_split, 0, 0, 0)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_explode, 0, 0, 0)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_create, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_from, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_of, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_fluent_str_random, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(fluent_str_method_entry) {
	PHP_ME(Fluent_Str, __construct, arginfo_fluent_str___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Fluent_Str, startsWith, arginfo_fluent_str_startswith, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, endsWith, arginfo_fluent_str_endswith, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, length, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, splitBy, arginfo_fluent_str_splitby, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, split, arginfo_fluent_str_split, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, explode, arginfo_fluent_str_explode, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, ignoreCase, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, ignoringCase, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, create, arginfo_fluent_str_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Fluent_Str, from, arginfo_fluent_str_from, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Fluent_Str, of, arginfo_fluent_str_of, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Fluent_Str, random, arginfo_fluent_str_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Fluent_Str, text, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Fluent_Str, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
