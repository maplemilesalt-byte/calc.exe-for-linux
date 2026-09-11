#include "ratpak/ratpak.h"

#define HNUMOBJ   PRAT
typedef HNUMOBJ * PHNUMOBJ;

#define NumObjAllocMem( cb )         zmalloc( cb )
#define NumObjFreeMem( h )           zfree( h ),(h=NULL)

void NumObjInvert( PHNUMOBJ phno );
#define NumObjNegate( phno )                ( ((PRAT)*phno)->pp->sign= -(((PRAT)*phno)->pp->sign) )
#define NumObjAbs( phno )                   ( ((PRAT)*phno)->pp->sign=1, ((PRAT)*phno)->pq->sign=1 )

extern void NumObjSin( PHNUMOBJ phno );
extern void NumObjCos( PHNUMOBJ phno );
extern void NumObjTan( PHNUMOBJ phno );
extern void NumObjAntiLog10( PHNUMOBJ phno );
extern void NumObjNot( PHNUMOBJ phno );

#define NumObjIsZero( hno )                 zerrat( hno )
#define NumObjIsLess( hno1, hno2 )          rat_lt( hno1, hno2 )
#define NumObjIsLessEq( hno1, hno2 )        rat_le( hno1, hno2 )
#define NumObjIsGreaterEq( hno1, hno2 )     rat_ge( hno1, hno2 )
#define NumObjIsEq( hno1, hno2 )            rat_equ(hno1, hno2 )

#define NumObjAssign( phnol, hnor )         if (1) { DUPRAT( (*phnol), hnor ); } else

void NumObjSetIntValue( PHNUMOBJ phnol, LONG i );
#define NumObjMakeNumber( fMantNeg, pszMant, fExpNeg, pszExp )      inrat( fMantNeg, pszMant, fExpNeg, pszExp )
void NumObjGetSzValue( LPTSTR *ppszNum, HNUMOBJ hnoNum, INT nRadix, NUMOBJ_FMT gafmt );
#define NumObjGetExp( hno )         LOGRATRADIX(hno)
#define NumObjCvtEpsilonToZero( phno )
#define NumObjAbortOperation( fAbort )  (fhalt=fAbort)
#define NumObjWasAborted()              (fhalt)
#define NumObjOK( hno )              ((hno) == NULL ? FALSE : TRUE)
#define NumObjDestroy( phno )            destroyrat( (*(phno)) )
#define DECLARE_HNUMOBJ( hno )       HNUMOBJ hno = NULL

void BaseOrPrecisionChanged( void );

#define HNO_ZERO                rat_zero
#define HNO_ONE_OVER_TWO        rat_half
#define HNO_ONE                 rat_one
#define HNO_TWO                 rat_two
#define HNO_180_OVER_PI         rad_to_deg
#define HNO_200_OVER_PI         rad_to_grad
#define HNO_2PI                 two_pi
#define HNO_PI                  pi
#define HNO_PI_OVER_TWO         pi_over_two
#define HNO_THREE_PI_OVER_TWO   one_pt_five_pi
