
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "fluent.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *fluent_str_ce;

ZEND_DECLARE_MODULE_GLOBALS(fluent)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(fluent)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Fluent_Str);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(fluent)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_fluent_globals *fluent_globals TSRMLS_DC)
{
	fluent_globals->initialized = 0;

	/* Cache Enabled */
	fluent_globals->cache_enabled = 1;

	/* Recursive Lock */
	fluent_globals->recursive_lock = 0;

	/* Static cache */
	memset(fluent_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_fluent_globals *fluent_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(fluent)
{
	zend_fluent_globals *fluent_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	fluent_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(fluent_globals_ptr);
	zephir_initialize_memory(fluent_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(fluent)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(fluent)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_FLUENT_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_FLUENT_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_FLUENT_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_FLUENT_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_FLUENT_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(fluent)
{
	php_zephir_init_globals(fluent_globals);
	php_zephir_init_module_globals(fluent_globals);
}

static PHP_GSHUTDOWN_FUNCTION(fluent)
{
	
}


zend_function_entry php_fluent_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_fluent_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry fluent_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_fluent_deps,
	PHP_FLUENT_EXTNAME,
	php_fluent_functions,
	PHP_MINIT(fluent),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(fluent),
#else
	NULL,
#endif
	PHP_RINIT(fluent),
	PHP_RSHUTDOWN(fluent),
	PHP_MINFO(fluent),
	PHP_FLUENT_VERSION,
	ZEND_MODULE_GLOBALS(fluent),
	PHP_GINIT(fluent),
	PHP_GSHUTDOWN(fluent),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(fluent),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_FLUENT
ZEND_GET_MODULE(fluent)
#endif
