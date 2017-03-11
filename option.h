#ifndef OPTION_H_
#define OPTION_H_

/* Values can be Some or None */
enum option_type {OPTION_NONE, OPTION_SOME};

#define DEFINE_OPTION_TYPE(content_type_name__, content_type__)	\
typedef struct {												\
	enum option_type type;										\
	content_type__ value;										\
} content_type_name__

#endif
