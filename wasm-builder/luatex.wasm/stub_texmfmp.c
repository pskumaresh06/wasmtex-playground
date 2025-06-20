// stub_texmfmp.c
#include <stddef.h>  // ← this defines NULL

const char *kpse_def = NULL;
const char *kpse_def_inst = NULL;
const char *TEX_format_default = "luatex";
const char *output_directory = NULL;
int recorder_enabled = 0;
int doing_leaders = 0;
char *cur_name = NULL;
char *cur_area = NULL;
char *cur_ext = NULL;
int program_name_set = 0;
void *font_tables = 0;

// New stubs for link errors
int pdf_cur_form = 0;
int pdf_last_obj = 0;
int dvi_buf_size = 0;
int pk_dpi = 0;
unsigned char *dvi_buf = NULL;
int input_file_callback_id = 0;
char *buffer = NULL;

int first = 0;
int max_buf_stack = 0;
char *format_ident = NULL;
int epochseconds = 0;
int microseconds = 0;
int log_opened_global = 0;
char *job_name = NULL;
void *fmt_file = NULL;
int biggest_used_mark = 0;
void *top_marks_array = NULL;
void *first_marks_array = NULL;
void *bot_marks_array = NULL;
void *split_first_marks_array = NULL;
void *split_bot_marks_array = NULL;
char *texmf_log_name = NULL;


int last = 0;

const char *format_name = "luatex";

// cur_file_name appears to be a char pointer
const char *cur_file_name = NULL;

// backend_out_control is likely a function pointer array
typedef void (*backend_control_fn_t)(void);  // Replace with real signature if needed
backend_control_fn_t backend_out_control[10] = { NULL };  // size 10 is arbitrary, adjust if needed

// From textoken.c
int is_in_csname = 0;
int long_state = 0;

// From texdeffont.c
char *name_in_progress = NULL;

// From filename.c
int ext_delimiter = '.';     // or 46
int area_delimiter = '/';    // or 47; adjust if your TeX engine uses something else
