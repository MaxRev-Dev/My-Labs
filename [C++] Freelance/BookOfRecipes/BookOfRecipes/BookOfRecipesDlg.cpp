Р В Р’В Р В Р вЂ№Р В Р’В Р В Р РЏР В Р’В Р В Р вЂ№Р В Р’В Р Р†Р вЂљРІвЂћвЂ“ 
 / /   B o o k O f R e c i p e s D l g . c p p   :   i m p l e m e n t a t i o n   f i l e  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
 # i n c l u d e   " B o o k O f R e c i p e s . h "  
 # i n c l u d e   " B o o k O f R e c i p e s D l g . h "  
 # i n c l u d e   " a f x d i a l o g e x . h "  
 # i n c l u d e   " R e c i p e . h "  
 # i n c l u d e   " t o o l s . h "  
 # i n c l u d e   < E x D i s p . h >  
 # i n c l u d e   < m s h t m l . h >  
 # i n c l u d e   < d i s p e x . h >  
 # i n c l u d e   < a t l b a s e . h >  
 # i n c l u d e   < a t l c o m c l i . h >  
 # i f d e f   _ D E B U G  
 # d e f i n e   n e w   D E B U G _ N E W  
 # e n d i f  
  
 / / h r e s u l t   w r a p  
 # d e f i n e   _ S ( a )   \  
         {   H R E S U L T   h r   =   ( a ) ;   i f   ( F A I L E D ( h r ) )   r e t u r n   h r ;   }    
  
  
 / /   c a s t   d i s p a t c h   d r i v e r   t o   i n t e r f a c e   t y p e  
 # d e f i n e   d i s p _ c a s t ( d i s p )   \  
         ( ( C C o m D i s p a t c h D r i v e r & ) ( v o i d ( s t a t i c _ c a s t < I D i s p a t c h * > ( d i s p ) ) ,   r e i n t e r p r e t _ c a s t < C C o m D i s p a t c h D r i v e r & > ( d i s p ) ) )  
  
 s t r u c t   C o m I n i t   {  
 	 C o m I n i t ( )   {   : : C o I n i t i a l i z e ( N U L L ) ;   }  
 	 ~ C o m I n i t ( )   {   C o U n i n i t i a l i z e ( ) ;   }  
 } ;  
  
 / /   C A b o u t D l g   d i a l o g   u s e d   f o r   A p p   A b o u t  
  
 c l a s s   C A b o u t D l g   :   p u b l i c   C D i a l o g E x  
 {  
 p u b l i c :  
 	 C A b o u t D l g ( ) ;  
  
 	 / /   D i a l o g   D a t a  
 # i f d e f   A F X _ D E S I G N _ T I M E  
 	 e n u m   {   I D D   =   I D D _ A B O U T B O X   } ;  
 # e n d i f  
  
 p r o t e c t e d :  
 	 v i r t u a l   v o i d   D o D a t a E x c h a n g e ( C D a t a E x c h a n g e *   p D X ) ;         / /   D D X / D D V   s u p p o r t  
  
 / /   I m p l e m e n t a t i o n  
 p r o t e c t e d :  
 	 D E C L A R E _ M E S S A G E _ M A P ( )  
 } ;  
  
 C A b o u t D l g : : C A b o u t D l g ( )   :   C D i a l o g E x ( I D D _ A B O U T B O X )  
 {  
 }  
  
 v o i d   C A b o u t D l g : : D o D a t a E x c h a n g e ( C D a t a E x c h a n g e *   p D X )  
 {  
 	 C D i a l o g E x : : D o D a t a E x c h a n g e ( p D X ) ;  
 }  
  
 B E G I N _ M E S S A G E _ M A P ( C A b o u t D l g ,   C D i a l o g E x )  
 E N D _ M E S S A G E _ M A P ( )  
  
  
 / /   C B o o k O f R e c i p e s D l g   d i a l o g  
  
 B E G I N _ D H T M L _ E V E N T _ M A P ( C B o o k O f R e c i p e s D l g )  
 	 D H T M L _ E V E N T _ O N C L I C K ( _ T ( " N e x t R e c i p e " ) ,   O n N e x t R e c i p e )  
 	 D H T M L _ E V E N T _ O N C L I C K ( _ T ( " P r e v R e c i p e " ) ,   O n P r e v R e c i p e )  
 	 D H T M L _ E V E N T _ O N C L I C K ( _ T ( " T o g g l e B t n " ) ,   O n T o g g l e B t n )  
 	 D H T M L _ E V E N T _ O N C L I C K ( _ T ( " R e t r y B t n " ) ,   O n R e t r y B t n )  
  
 E N D _ D H T M L _ E V E N T _ M A P ( )  
  
  
 C B o o k O f R e c i p e s D l g : : C B o o k O f R e c i p e s D l g ( C W n d *   p P a r e n t   / * = n u l l p t r * / )  
 	 :   C D H t m l D i a l o g ( I D D _ B O O K O F R E C I P E S _ D I A L O G ,   I D R _ H T M L _ B O O K O F R E C I P E S _ D I A L O G ,   p P a r e n t )  
 {  
 	 m _ h I c o n   =   A f x G e t A p p ( ) - > L o a d I c o n ( I D R _ M A I N F R A M E ) ;  
 }  
  
 v o i d   C B o o k O f R e c i p e s D l g : : D o D a t a E x c h a n g e ( C D a t a E x c h a n g e *   p D X )  
 {  
 	 C D H t m l D i a l o g : : D o D a t a E x c h a n g e ( p D X ) ;  
 }  
  
 B E G I N _ M E S S A G E _ M A P ( C B o o k O f R e c i p e s D l g ,   C D H t m l D i a l o g )  
 	 O N _ W M _ S Y S C O M M A N D ( )  
 	 O N _ C O M M A N D ( I D _ A B O U T ,   & C B o o k O f R e c i p e s D l g : : O n A b o u t )  
 	 O N _ W M _ A C T I V A T E A P P ( )  
 	 O N _ W M _ C R E A T E ( )    
 E N D _ M E S S A G E _ M A P ( )  
  
  
 / /   C B o o k O f R e c i p e s D l g   m e s s a g e   h a n d l e r s  
  
 b o o l   L i s t I n i t i a l i z e d   =   f a l s e ;  
 b o o l   R e c i p e S h o w n   =   f a l s e ;  
 i n t   * i m a g e I n d e x   =   n e w   i n t {   - 1   } ;   / / f o r   r e f   i n   m e t h o d s  
 b o o l   h a n d l e d I n d e x   =   f a l s e ;  
  
 i n l i n e   w s t r i n g   G e t S h o w B t n ( w s t r i n g   t e x t )   {  
 	 r e t u r n     L "   < b u t t o n   S T Y L E = \ " W I D T H : 1 0 0 \ "   I D = \ " T o g g l e B t n \ "   t y p e = \ " b u t t o n \ "   c l a s s = \ " b t n   b t n - i n f o \ " > "   +   t e x t   +   L " < / b u t t o n > " ;  
 }  
  
 B O O L   C B o o k O f R e c i p e s D l g : : O n I n i t D i a l o g ( )  
 {  
 	 S e t H o s t F l a g s ( D O C H O S T U I F L A G _ F L A T _ S C R O L L B A R ) ;  
 	 C D H t m l D i a l o g : : O n I n i t D i a l o g ( ) ;  
  
 	 / /   S e t   t h e   i c o n   f o r   t h i s   d i a l o g .     T h e   f r a m e w o r k   d o e s   t h i s   a u t o m a t i c a l l y  
 	 / /     w h e n   t h e   a p p l i c a t i o n ' s   m a i n   w i n d o w   i s   n o t   a   d i a l o g  
 	 S e t I c o n ( m _ h I c o n ,   T R U E ) ; 	 	 	 / /   S e t   b i g   i c o n  
 	 S e t I c o n ( m _ h I c o n ,   F A L S E ) ; 	 	 / /   S e t   s m a l l   i c o n  
  
 	 r e t u r n   T R U E ;     / /   r e t u r n   T R U E     u n l e s s   y o u   s e t   t h e   f o c u s   t o   a   c o n t r o l  
 }  
  
 v o i d   C B o o k O f R e c i p e s D l g : : O n S y s C o m m a n d ( U I N T   n I D ,   L P A R A M   l P a r a m )  
 {  
 	 i f   ( ( n I D   &   0 x F F F 0 )   = =   I D M _ A B O U T B O X )  
 	 {  
 	 	 C A b o u t D l g   d l g A b o u t ;  
 	 	 d l g A b o u t . D o M o d a l ( ) ;  
 	 }  
 	 e l s e  
 	 {  
 	 	 C D H t m l D i a l o g : : O n S y s C o m m a n d ( n I D ,   l P a r a m ) ;  
 	 }  
 }  
  
 / /   I f   y o u   a d d   a   m i n i m i z e   b u t t o n   t o   y o u r   d i a l o g ,   y o u   w i l l   n e e d   t h e   c o d e   b e l o w  
 / /     t o   d r a w   t h e   i c o n .     F o r   M F C   a p p l i c a t i o n s   u s i n g   t h e   d o c u m e n t / v i e w   m o d e l ,  
 / /     t h i s   i s   a u t o m a t i c a l l y   d o n e   f o r   y o u   b y   t h e   f r a m e w o r k .  
 v o i d   C B o o k O f R e c i p e s D l g : : O n P a i n t ( )  
 {  
  
 	 i f   ( I s I c o n i c ( ) )  
 	 {  
 	 	 C P a i n t D C   d c ( t h i s ) ;   / /   d e v i c e   c o n t e x t   f o r   p a i n t i n g  
  
 	 	 S e n d M e s s a g e ( W M _ I C O N E R A S E B K G N D ,   r e i n t e r p r e t _ c a s t < W P A R A M > ( d c . G e t S a f e H d c ( ) ) ,   0 ) ;  
  
 	 	 / /   C e n t e r   i c o n   i n   c l i e n t   r e c t a n g l e  
 	 	 i n t   c x I c o n   =   G e t S y s t e m M e t r i c s ( S M _ C X I C O N ) ;  
 	 	 i n t   c y I c o n   =   G e t S y s t e m M e t r i c s ( S M _ C Y I C O N ) ;  
 	 	 C R e c t   r e c t ;  
 	 	 G e t C l i e n t R e c t ( & r e c t ) ;  
 	 	 i n t   x   =   ( r e c t . W i d t h ( )   -   c x I c o n   +   1 )   /   2 ;  
 	 	 i n t   y   =   ( r e c t . H e i g h t ( )   -   c y I c o n   +   1 )   /   2 ;  
  
 	 	 / /   D r a w   t h e   i c o n  
 	 	 d c . D r a w I c o n ( x ,   y ,   m _ h I c o n ) ;  
 	 }  
 	 e l s e  
 	 {  
 	 	 C D H t m l D i a l o g : : O n P a i n t ( ) ;  
 	 }  
 }  
  
 / /   T h e   s y s t e m   c a l l s   t h i s   f u n c t i o n   t o   o b t a i n   t h e   c u r s o r   t o   d i s p l a y   w h i l e   t h e   u s e r   d r a g s  
 / /     t h e   m i n i m i z e d   w i n d o w .  
 H C U R S O R   C B o o k O f R e c i p e s D l g : : O n Q u e r y D r a g I c o n ( )  
 {  
 	 r e t u r n   s t a t i c _ c a s t < H C U R S O R > ( m _ h I c o n ) ;  
 }  
  
 H R E S U L T   C B o o k O f R e c i p e s D l g : : O n N e x t R e c i p e ( I H T M L E l e m e n t *   / * p E l e m e n t * / )  
 {  
 	 R e c i p e S h o w n   =   h a n d l e d I n d e x   =   f a l s e ;  
 	 ( * i m a g e I n d e x ) + + ;   / / c h a n g e   i n d e x ;  
 	 S e t R e c i p e W i t h I n d e x ( i m a g e I n d e x ) ;  
  
 	 r e t u r n   S _ O K ;  
 }  
 H R E S U L T   C B o o k O f R e c i p e s D l g : : O n P r e v R e c i p e ( I H T M L E l e m e n t *   / * p E l e m e n t * / )  
 {  
 	 R e c i p e S h o w n   =   h a n d l e d I n d e x   =   f a l s e ;  
 	 ( * i m a g e I n d e x ) - - ;   / / c h a n g e   i n d e x ;  
 	 S e t R e c i p e W i t h I n d e x ( i m a g e I n d e x ) ;  
 	 r e t u r n   S _ O K ;  
 }  
  
 i n l i n e   v o i d   C B o o k O f R e c i p e s D l g : : S e t R e c i p e W i t h I n d e x ( i n t   * i )   {  
 	 a u t o   l i s t   =   c o n t a i n e r . G e t L i s t ( ) ;  
 	 i f   ( l i s t . s i z e ( )   >   0 )   {  
  
 	 	 E v a l S c r i p t ( m _ s p H t m l D o c ,   L " t r y { p l a y e r . d e s t r o y ( ) } c a t c h ( e ) { } " ) ;   / / d e s t r o y   p l a y e r  
  
 	 	 s e l e c t e d R e c i p e   =   l i s t [  
 	 	 	 * i   < =   - 1   ?   * i   =   ( i n t ) l i s t . s i z e ( )   -   1   :   / / l o o p   l i s t  
 	 	 	 	 * i   > =   ( i n t ) l i s t . s i z e ( )   -   1   ?   * i   =   0   :   * i ] ;  
  
 	 	 / / u p d a t e   u i   s t a t e  
 	 	 S e t E l e m I n n e r ( L " I m g H o l d e r " ,   L " < i m g   c l a s s = \ " c a r d - i m g - t o p \ "   s r c = ' "   +   s e l e c t e d R e c i p e . I m a g e U r l   +   L " ' / > " ) ;  
 	 	 S e t E l e m I n n e r ( L " h e a d e r T e x t " ,   L " < h 2 > "   +   s e l e c t e d R e c i p e . T i t l e   +   L " < h 2 / > " ) ;  
 	 	 S e t E l e m I n n e r ( L " h e a d e r D e s c " ,   L " < p > "   +   s e l e c t e d R e c i p e . C o n t e n t I n t r o   +   L " < p / > " ) ;  
 	 	 S e t E l e m I n n e r ( L " T o g g l e B t n C o n t a i n e r " ,   G e t S h o w B t n ( L " S h o w   m o r e " ) ) ;  
 	 	 S e t E l e m I n n e r ( L " C o n t e n t C o n t a i n e r " ,   L " " ) ;  
 	 }  
 }  
  
 / / e v a l u a t e   s c r i p t   i n   d o c u m e n t  
 H R E S U L T   C B o o k O f R e c i p e s D l g : : E v a l S c r i p t ( A T L : : C C o m P t r < I H T M L D o c u m e n t 2 >   d o c ,   w s t r i n g   c o n t e n t )   {  
  
 	 C C o m P t r < I H T M L W i n d o w 2 >   h t m l W i n d o w ;  
 	 _ S ( d o c - > g e t _ p a r e n t W i n d o w ( & h t m l W i n d o w ) ) ;  
 	 C C o m P t r < I D i s p a t c h E x >   d i s p a t c h W i n d o w ;  
 	 _ S ( h t m l W i n d o w - > Q u e r y I n t e r f a c e ( & d i s p a t c h W i n d o w ) ) ;  
  
 	 C C o m B S T R   _ _ e x e c S c r i p t C o d e ( c o n t e n t . c _ s t r ( ) ) ;  
  
 	 D I S P I D   d i s p i d   =   - 1 ;  
 	 _ S ( d i s p a t c h W i n d o w - > G e t D i s p I D ( C C o m B S T R ( " e v a l " ) ,   f d e x N a m e C a s e S e n s i t i v e ,   & d i s p i d ) ) ;  
 	 _ S ( d i s p _ c a s t ( d i s p a t c h W i n d o w ) . I n v o k e 1 ( d i s p i d ,   & C C o m V a r i a n t ( _ _ e x e c S c r i p t C o d e ) ) ) ;  
 	 r e t u r n   S _ O K ;  
 }  
  
 H R E S U L T   C B o o k O f R e c i p e s D l g : : O n T o g g l e B t n ( I H T M L E l e m e n t *   p E l e m e n t )   {  
 	 i f   ( ! R e c i p e S h o w n )   {  
 	 	 i f   ( s e l e c t e d R e c i p e . C o n t e n t   = =   L " " )  
 	 	 	 c o n t a i n e r . G e t R e c i p e F u l l ( s e l e c t e d R e c i p e ) ;  
 	 	 a u t o   c o n t e n t   =   t o o l s : : s t r : : t r i m ( s e l e c t e d R e c i p e . C o n t e n t )   = =   L " "   ?   L " S o r r y ,   t h i s   r e c i p e   i s   e m p t y ! "   :   s e l e c t e d R e c i p e . C o n t e n t ;  
 	 	 i f   ( t o o l s : : s t r : : W s t r T o U t f 8 S t r ( c o n t e n t ) . f i n d ( " n e w   Y T . P l a y e r " )   = =   w s t r i n g : : n p o s )   {  
 	 	 	 / / n o t   a   s c r i p t  
 	 	 	 S e t E l e m I n n e r ( L " C o n t e n t C o n t a i n e r " ,   c o n t e n t ) ;  
 	 	 }  
 	 	 e l s e   {  
 	 	 	 S e t E l e m I n n e r ( L " P l a y e r W r a p " ,   L " < d i v   i d = \ " y t p l a y e r \ "   c l a s s = \ " w - 1 0 0   t e x t - c e n t e r   j u s t i f y - c o n t e n t - c e n t e r \ " > < / d i v > " ) ;  
 	 	 	 E v a l S c r i p t ( m _ s p H t m l D o c ,   c o n t e n t ) ;  
 	 	 }  
 	 	 S e t E l e m I n n e r ( L " T o g g l e B t n C o n t a i n e r " ,   G e t S h o w B t n ( L " H i d e " ) ) ;  
 	 	 R e c i p e S h o w n   =   t r u e ;  
 	 }  
 	 e l s e   {  
 	 	 S e t E l e m I n n e r ( L " T o g g l e B t n C o n t a i n e r " ,   G e t S h o w B t n ( L " S h o w   m o r e " ) ) ;  
 	 	 E v a l S c r i p t ( m _ s p H t m l D o c ,   L " t r y { p l a y e r . d e s t r o y ( ) } c a t c h ( e ) { } " ) ;   / / d e s t r o y   p l a y e r ,   c a u s e   i t   g l o b a l  
 	 	 S e t E l e m I n n e r ( L " C o n t e n t C o n t a i n e r " ,   L " " ) ;  
 	 	 R e c i p e S h o w n   =   f a l s e ;  
 	 }  
 	 r e t u r n   S _ O K ;  
 }  
 H R E S U L T   C B o o k O f R e c i p e s D l g : : O n R e t r y B t n ( I H T M L E l e m e n t *   / * p E l e m e n t * / )   {  
  
 	 i f   ( ! c o n t a i n e r . G e t L i s t ( ) . s i z e ( ) )   {  
 	 	 c o n t a i n e r   =   R e c i p e F e t c h : : R e c i p e F e t c h ( ) ;  
 	 	 c o n t a i n e r . F e t c h R o o t ( ) ;  
 	 }  
 	 / / c h e c k   a g a i n   a n d   t r y   t o   s e t   u p   i t e m  
 	 i f   ( c o n t a i n e r . G e t L i s t ( ) . s i z e ( ) )   {  
 	 	 L i s t I n i t i a l i z e d   =   t r u e ;  
 	 	 S e t R e c i p e W i t h I n d e x ( i m a g e I n d e x ) ;  
 	 }  
 	 r e t u r n   S _ O K ;  
 }  
 H R E S U L T   C B o o k O f R e c i p e s D l g : : S e t E l e m I n n e r ( w s t r i n g   i d ,   w s t r i n g   i n n e r H t m l )   {  
  
 	 I H T M L E l e m e n t *   p L i n k E l e m e n t   =   N U L L ;  
 	 _ b s t r _ t   b   =   i n n e r H t m l . c _ s t r ( ) ;  
 	 a u t o   w s x   =   t o o l s : : s t r : : W s t r T o U t f 8 S t r ( i d ) ;  
 	 a u t o   s x   =   w s x . c _ s t r ( ) ;  
 	 i f   ( G e t E l e m e n t ( s x ,   & p L i n k E l e m e n t )   = =   S _ O K   & &  
 	 	 p L i n k E l e m e n t   ! =   N U L L )  
 	 {  
 	 	 p L i n k E l e m e n t - > p u t _ i n n e r H T M L ( b ) ;  
  
 	 	 p L i n k E l e m e n t - > R e l e a s e ( ) ;  
 	 	 r e t u r n   S _ O K ;  
 	 }  
 	 r e t u r n   S _ F A L S E ;  
 }  
  
 v o i d   C B o o k O f R e c i p e s D l g : : O n A b o u t ( )  
 {  
 	 C A b o u t D l g   d l g A b o u t ;  
 	 d l g A b o u t . D o M o d a l ( ) ;  
 }  
  
  
 i n t   C B o o k O f R e c i p e s D l g : : O n C r e a t e ( L P C R E A T E S T R U C T   l p C r e a t e S t r u c t )  
 {  
 	 i f   ( C D H t m l D i a l o g : : O n C r e a t e ( l p C r e a t e S t r u c t )   = =   - 1 )  
 	 	 r e t u r n   - 1 ;  
  
 	 i f   ( ! L i s t I n i t i a l i z e d )   {  
 	 	 c o n t a i n e r   =   R e c i p e F e t c h : : R e c i p e F e t c h ( ) ;  
 	 	 c o n t a i n e r . F e t c h R o o t ( ) ;  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 v o i d   C B o o k O f R e c i p e s D l g : : O n D o c u m e n t C o m p l e t e (  
 	 L P D I S P A T C H   p D i s p ,  
 	 L P C T S T R   s z U r l  
 )   {  
  
 	 i f   ( ! L i s t I n i t i a l i z e d )   {  
 	 	 i f   ( ! c o n t a i n e r . G e t L i s t ( ) . s i z e ( ) )   / / v e c t o r   i s   e m p t y   c a u s e   w e   a r e   o f f l i n e  
 	 	 {  
 	 	 	 S e t E l e m I n n e r ( L " h e a d e r D e s c " ,   L " N o   i n t e r n e t   c o n n e c t i o n   d e t e c t e d " ) ;  
 	 	 	 S e t E l e m I n n e r ( L " T o g g l e B t n C o n t a i n e r " ,   L "   < B U T T O N   S T Y L E = \ " W I D T H : 1 0 0 \ "   I D = \ " R e t r y B t n \ " > T r y   A g a i n ! < / B U T T O N > " ) ;  
 	 	 }  
 	 	 e l s e   {  
 	 	 	 a u t o   p l a y e r I n i t   =  
 	 	 	 	 L "   v a r   t a g   =   d o c u m e n t . c r e a t e E l e m e n t ( ' s c r i p t ' ) ; " \  
 	 	 	 	 "   t a g . s r c   =   \ " h t t p s : / / w w w . y o u t u b e . c o m / p l a y e r _ a p i \ " ; " \  
 	 	 	 	 "   v a r   f i r s t S c r i p t T a g   =   d o c u m e n t . g e t E l e m e n t s B y T a g N a m e ( ' s c r i p t ' ) [ 0 ] ; " \  
 	 	 	 	 "   f i r s t S c r i p t T a g . p a r e n t N o d e . i n s e r t B e f o r e ( t a g ,   f i r s t S c r i p t T a g ) ; " ;  
 	 	 	 E v a l S c r i p t ( m _ s p H t m l D o c ,   p l a y e r I n i t ) ;  
  
 	 	 	 L i s t I n i t i a l i z e d   =   t r u e ;  
 	 	 	 S e t R e c i p e W i t h I n d e x ( i m a g e I n d e x ) ;  
 	 	 }  
 	 }  
 }  
 