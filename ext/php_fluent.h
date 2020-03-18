
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_FLUENT_H
#define PHP_FLUENT_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_FLUENT_NAME        "fluent"
#define PHP_FLUENT_VERSION     "0.0.1"
#define PHP_FLUENT_EXTNAME     "fluent"
#define PHP_FLUENT_AUTHOR      "Stephen Lake"
#define PHP_FLUENT_ZEPVERSION  "0.12.17-$Id$"
#define PHP_FLUENT_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(fluent)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(fluent)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(fluent)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(fluent, v)
#else
	#define ZEPHIR_GLOBAL(v) (fluent_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_fluent_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(fluent_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(fluent_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def fluent_globals
#define zend_zephir_globals_def zend_fluent_globals

extern zend_module_entry fluent_module_entry;
#define phpext_fluent_ptr &fluent_module_entry

#endif
