static inline struct pthread *__pthread_self()
{
	char *tp;
	__asm__ ("or %0, $tp, $zero" : "=r" (tp) );
	return (pthread_t)(tp -  sizeof(struct pthread));
}

#define TLS_ABOVE_TP
#define GAP_ABOVE_TP 0
#define TP_ADJ(p) ((char *)(p) + sizeof(struct pthread))

#define DTP_OFFSET 0

#define MC_PC pc
