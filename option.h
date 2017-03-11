#ifndef OPTION_H_
#define OPTION_H_

/* Values can be Some or None */
enum option_type {OPTION_NONE, OPTION_SOME};

#define OPTION_TYPEDEF(content_type__, content_type_name__)		\
typedef struct {												\
	enum option_type type;										\
	content_type__ value;										\
} content_type_name__

#define OPTION_NONE(a) do {										\
	(a)->type = OPTION_NONE;									\
} while(0)

#define OPTION_SOME(a, val)	do {								\
	(a)->type = OPTION_SOME;									\
	(a)->value = (val);											\
} while(0)

#endif
