яю/ /   C I R C L E S . c p p   :   D e f i n e s   t h e   e n t r y   p o i n t   f o r   t h e   a p p l i c a t i o n .  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
  
 # i n c l u d e   " m a t h . h "  
 # i n c l u d e   " C i r c l e . h "  
 # i n c l u d e   " R e c u r P a r a m . h "  
 # i n c l u d e   < s t d i o . h >  
 # i n c l u d e   " C I R C L E S . h "  
  
 # d e f i n e   M A X _ L O A D S T R I N G   1 0 0  
  
 / /   G l o b a l   V a r i a b l e s :  
 H I N S T A N C E   h I n s t ;                                                                 / /   c u r r e n t   i n s t a n c e  
 W C H A R   s z T i t l e [ M A X _ L O A D S T R I N G ] ;                                     / /   T h e   t i t l e   b a r   t e x t  
 W C H A R   s z W i n d o w C l a s s [ M A X _ L O A D S T R I N G ] ;                         / /   t h e   m a i n   w i n d o w   c l a s s   n a m e  
  
 / /   F o r w a r d   d e c l a r a t i o n s   o f   f u n c t i o n s   i n c l u d e d   i n   t h i s   c o d e   m o d u l e :  
 A T O M                                 M y R e g i s t e r C l a s s ( H I N S T A N C E   h I n s t a n c e ) ;  
 B O O L                                 I n i t I n s t a n c e ( H I N S T A N C E ,   i n t ) ;  
 L R E S U L T   C A L L B A C K         W n d P r o c ( H W N D ,   U I N T ,   W P A R A M ,   L P A R A M ) ;  
 I N T _ P T R   C A L L B A C K         A b o u t ( H W N D ,   U I N T ,   W P A R A M ,   L P A R A M ) ;  
  
 / / C u s t o m  
 R e c u r P a r a m   * p R e c u r ;  
 L R E S U L T   C A L L B A C K   T e s t R e c u r s e ( H W N D ,   U I N T ,   W P A R A M ,   L P A R A M ) ;  
 v o i d   H a n d l e O n O k ( H W N D   h D l g ) ;  
 v o i d   H a n d l e O n I n i t D i a l o g ( H W N D   h D l g ) ;  
 v o i d   D r a w C i r c l e s ( H D C   h d c ,   i n t   w ,   i n t   h ,   i n t   n ,   d o u b l e   c ) ;  
  
  
  
 i n t   A P I E N T R Y   w W i n M a i n ( _ I n _   H I N S T A N C E   h I n s t a n c e ,  
 	 _ I n _ o p t _   H I N S T A N C E   h P r e v I n s t a n c e ,  
 	 _ I n _   L P W S T R         l p C m d L i n e ,  
 	 _ I n _   i n t               n C m d S h o w )  
 {  
 	 U N R E F E R E N C E D _ P A R A M E T E R ( h P r e v I n s t a n c e ) ;  
 	 U N R E F E R E N C E D _ P A R A M E T E R ( l p C m d L i n e ) ;  
  
 	 / /   T O D O :   P l a c e   c o d e   h e r e .  
  
 	 / /   I n i t i a l i z e   g l o b a l   s t r i n g s  
 	 L o a d S t r i n g W ( h I n s t a n c e ,   I D S _ A P P _ T I T L E ,   s z T i t l e ,   M A X _ L O A D S T R I N G ) ;  
 	 L o a d S t r i n g W ( h I n s t a n c e ,   I D C _ C I R C L E S ,   s z W i n d o w C l a s s ,   M A X _ L O A D S T R I N G ) ;  
 	 M y R e g i s t e r C l a s s ( h I n s t a n c e ) ;  
  
 	 / /   P e r f o r m   a p p l i c a t i o n   i n i t i a l i z a t i o n :  
 	 i f   ( ! I n i t I n s t a n c e ( h I n s t a n c e ,   n C m d S h o w ) )  
 	 {  
 	 	 r e t u r n   F A L S E ;  
 	 }  
  
 	 H A C C E L   h A c c e l T a b l e   =   L o a d A c c e l e r a t o r s ( h I n s t a n c e ,   M A K E I N T R E S O U R C E ( I D C _ C I R C L E S ) ) ;  
  
 	 M S G   m s g ;  
  
 	 / /   M a i n   m e s s a g e   l o o p :  
 	 w h i l e   ( G e t M e s s a g e ( & m s g ,   n u l l p t r ,   0 ,   0 ) )  
 	 {  
 	 	 i f   ( ! T r a n s l a t e A c c e l e r a t o r ( m s g . h w n d ,   h A c c e l T a b l e ,   & m s g ) )  
 	 	 {  
 	 	 	 T r a n s l a t e M e s s a g e ( & m s g ) ;  
 	 	 	 D i s p a t c h M e s s a g e ( & m s g ) ;  
 	 	 }  
 	 }  
 	 i f   ( p R e c u r   ! =   N U L L )   d e l e t e   p R e c u r ;  
 	 r e t u r n   ( i n t ) m s g . w P a r a m ;  
 }  
  
  
  
 / /  
 / /     F U N C T I O N :   M y R e g i s t e r C l a s s ( )  
 / /  
 / /     P U R P O S E :   R e g i s t e r s   t h e   w i n d o w   c l a s s .  
 / /  
 A T O M   M y R e g i s t e r C l a s s ( H I N S T A N C E   h I n s t a n c e )  
 {  
 	 W N D C L A S S E X W   w c e x ;  
  
 	 w c e x . c b S i z e   =   s i z e o f ( W N D C L A S S E X ) ;  
  
 	 w c e x . s t y l e   =   C S _ H R E D R A W   |   C S _ V R E D R A W ;  
 	 w c e x . l p f n W n d P r o c   =   W n d P r o c ;  
 	 w c e x . c b C l s E x t r a   =   0 ;  
 	 w c e x . c b W n d E x t r a   =   0 ;  
 	 w c e x . h I n s t a n c e   =   h I n s t a n c e ;  
 	 w c e x . h I c o n   =   L o a d I c o n ( h I n s t a n c e ,   M A K E I N T R E S O U R C E ( I D I _ C I R C L E S ) ) ;  
 	 w c e x . h C u r s o r   =   L o a d C u r s o r ( n u l l p t r ,   I D C _ A R R O W ) ;  
 	 w c e x . h b r B a c k g r o u n d   =   ( H B R U S H ) ( C O L O R _ W I N D O W   +   1 ) ;  
 	 w c e x . l p s z M e n u N a m e   =   M A K E I N T R E S O U R C E W ( I D C _ C I R C L E S ) ;  
 	 w c e x . l p s z C l a s s N a m e   =   s z W i n d o w C l a s s ;  
 	 w c e x . h I c o n S m   =   L o a d I c o n ( w c e x . h I n s t a n c e ,   M A K E I N T R E S O U R C E ( I D I _ S M A L L ) ) ;  
  
 	 r e t u r n   R e g i s t e r C l a s s E x W ( & w c e x ) ;  
 }  
  
 / /  
 / /       F U N C T I O N :   I n i t I n s t a n c e ( H I N S T A N C E ,   i n t )  
 / /  
 / /       P U R P O S E :   S a v e s   i n s t a n c e   h a n d l e   a n d   c r e a t e s   m a i n   w i n d o w  
 / /  
 / /       C O M M E N T S :  
 / /  
 / /                 I n   t h i s   f u n c t i o n ,   w e   s a v e   t h e   i n s t a n c e   h a n d l e   i n   a   g l o b a l   v a r i a b l e   a n d  
 / /                 c r e a t e   a n d   d i s p l a y   t h e   m a i n   p r o g r a m   w i n d o w .  
 / /  
 B O O L   I n i t I n s t a n c e ( H I N S T A N C E   h I n s t a n c e ,   i n t   n C m d S h o w )  
 {  
 	 h I n s t   =   h I n s t a n c e ;   / /   S t o r e   i n s t a n c e   h a n d l e   i n   o u r   g l o b a l   v a r i a b l e  
  
 	 H W N D   h W n d   =   C r e a t e W i n d o w W ( s z W i n d o w C l a s s ,   s z T i t l e ,   W S _ O V E R L A P P E D W I N D O W ,  
 	 	 C W _ U S E D E F A U L T ,   0 ,   C W _ U S E D E F A U L T ,   0 ,   n u l l p t r ,   n u l l p t r ,   h I n s t a n c e ,   n u l l p t r ) ;  
  
 	 i f   ( ! h W n d )  
 	 {  
 	 	 r e t u r n   F A L S E ;  
 	 }  
  
 	 p R e c u r   =   n e w   R e c u r P a r a m ;  
  
 	 S h o w W i n d o w ( h W n d ,   n C m d S h o w ) ;  
 	 U p d a t e W i n d o w ( h W n d ) ;  
  
 	 r e t u r n   T R U E ;  
 }  
  
 / /  
 / /     F U N C T I O N :   W n d P r o c ( H W N D ,   U I N T ,   W P A R A M ,   L P A R A M )  
 / /  
 / /     P U R P O S E :     P r o c e s s e s   m e s s a g e s   f o r   t h e   m a i n   w i n d o w .  
 / /  
 / /     W M _ C O M M A N D     -   p r o c e s s   t h e   a p p l i c a t i o n   m e n u  
 / /     W M _ P A I N T         -   P a i n t   t h e   m a i n   w i n d o w  
 / /     W M _ D E S T R O Y     -   p o s t   a   q u i t   m e s s a g e   a n d   r e t u r n  
 / /  
 / /  
 L R E S U L T   C A L L B A C K   W n d P r o c ( H W N D   h W n d ,   U I N T   m e s s a g e ,   W P A R A M   w P a r a m ,   L P A R A M   l P a r a m )  
 {  
 	 s w i t c h   ( m e s s a g e )  
 	 {  
 	 c a s e   W M _ C O M M A N D :  
 	 {  
 	 	 i n t   w m I d   =   L O W O R D ( w P a r a m ) ;  
 	 	 / /   P a r s e   t h e   m e n u   s e l e c t i o n s :  
 	 	 s w i t c h   ( w m I d )  
 	 	 {  
 	 	 c a s e   I D M _ A B O U T :  
 	 	 	 D i a l o g B o x ( h I n s t ,   M A K E I N T R E S O U R C E ( I D D _ A B O U T B O X ) ,   h W n d ,   A b o u t ) ;  
 	 	 	 b r e a k ;  
 	 	 c a s e   I D M _ E X I T :  
 	 	 	 D e s t r o y W i n d o w ( h W n d ) ;  
 	 	 	 b r e a k ;  
 	 	 c a s e   I D M _ T E S T _ P A R A M :   {   / / t e s t   p a r a m  
 	 	 	 i f   ( D i a l o g B o x ( h I n s t ,   ( L P C T S T R ) I D D _ D I A L O G _ P A R A M ,   h W n d ,   ( D L G P R O C ) T e s t R e c u r s e )   = =   I D O K )   {  
 	 	 	 	 R E C T   r c ;  
 	 	 	 	 G e t C l i e n t R e c t ( h W n d ,   & r c ) ;   / /   f u l l   r e d r a w  
 	 	 	 	 I n v a l i d a t e R e c t ( h W n d ,   & r c ,   T R U E ) ;  
 	 	 	 }  
 	 	 	 b r e a k ;  
 	 	 }  
 	 	 d e f a u l t :  
 	 	 	 r e t u r n   D e f W i n d o w P r o c ( h W n d ,   m e s s a g e ,   w P a r a m ,   l P a r a m ) ;  
 	 	 }  
 	 }  
 	 b r e a k ;  
 	 c a s e   W M _ P A I N T :  
 	 {  
 	 	 P A I N T S T R U C T   p s ;  
 	 	 H D C   h d c   =   B e g i n P a i n t ( h W n d ,   & p s ) ;  
 	 	 R E C T   r t ;    
 	 	 G e t C l i e n t R e c t ( h W n d ,   & r t ) ;  
 	 	 R e d r a w W i n d o w ( h W n d ,   & r t ,   N U L L ,   R D W _ E R A S E ) ;  
 	 	 G e t S t o c k O b j e c t ( B L A C K _ P E N ) ;  
 	 	 D r a w C i r c l e s ( h d c ,   ( r t . r i g h t   -   r t . l e f t )   /   2 ,   ( r t . b o t t o m   -   r t . t o p )   /   2 ,  
 	 	 	 p R e c u r - > m _ n ,  
 	 	 	 p R e c u r - > m _ c ) ;  
 	 	 E n d P a i n t ( h W n d ,   & p s ) ;  
 	 }  
 	 b r e a k ;  
 	 c a s e   W M _ D E S T R O Y :  
 	 	 P o s t Q u i t M e s s a g e ( 0 ) ;  
 	 	 b r e a k ;  
 	 d e f a u l t :  
 	 	 r e t u r n   D e f W i n d o w P r o c ( h W n d ,   m e s s a g e ,   w P a r a m ,   l P a r a m ) ;  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 / /   M e s s a g e   h a n d l e r   f o r   a b o u t   b o x .  
 I N T _ P T R   C A L L B A C K   A b o u t ( H W N D   h D l g ,   U I N T   m e s s a g e ,   W P A R A M   w P a r a m ,   L P A R A M   l P a r a m )  
 {  
 	 U N R E F E R E N C E D _ P A R A M E T E R ( l P a r a m ) ;  
 	 s w i t c h   ( m e s s a g e )  
 	 {  
 	 c a s e   W M _ I N I T D I A L O G :  
 	 	 r e t u r n   ( I N T _ P T R ) T R U E ;  
  
 	 c a s e   W M _ C O M M A N D :  
 	 	 i f   ( L O W O R D ( w P a r a m )   = =   I D O K   | |   L O W O R D ( w P a r a m )   = =   I D C A N C E L )  
 	 	 {  
 	 	 	 E n d D i a l o g ( h D l g ,   L O W O R D ( w P a r a m ) ) ;  
 	 	 	 r e t u r n   ( I N T _ P T R ) T R U E ;  
 	 	 }  
 	 	 b r e a k ;  
 	 }  
 	 r e t u r n   ( I N T _ P T R ) F A L S E ;  
 }  
  
 L R E S U L T   C A L L B A C K   T e s t R e c u r s e ( H W N D   h D l g ,   U I N T   m e s s ,  
 	 W P A R A M   w P a r ,   L P A R A M   l P a r )  
 {  
 	 s w i t c h   ( m e s s )  
 	 {  
 	 c a s e   W M _ I N I T D I A L O G :   {  
 	 	 H a n d l e O n I n i t D i a l o g ( h D l g ) ;  
 	 	 b r e a k ;  
 	 }  
 	 c a s e   W M _ C O M M A N D :   {  
 	 	 i f   ( L O W O R D ( w P a r )   = =   I D C A N C E L )   {  
 	 	 	 E n d D i a l o g ( h D l g ,   L O W O R D ( w P a r ) ) ;  
 	 	 	 r e t u r n   T R U E ;  
 	 	 }  
 	 	 i f   ( L O W O R D ( w P a r )   = =   I D O K )   {  
 	 	 	 H a n d l e O n O k ( h D l g ) ;  
 	 	 	 E n d D i a l o g ( h D l g ,   L O W O R D ( w P a r ) ) ;  
 	 	 	 r e t u r n   T R U E ;  
 	 	 }  
 	 	 b r e a k ;  
 	 }  
 	 d e f a u l t : 
 	 	 b r e a k ;  
 	 }  
 	 r e t u r n   F A L S E ;  
 }  
  
 v o i d   H a n d l e O n O k ( H W N D   h D l g )  
 {  
 	 w c h a r _ t   b u f f [ 2 0 ] ,   * p E n d ;  
 	 G e t D l g I t e m T e x t ( h D l g ,   I D C _ E D I T _ N ,   b u f f ,   2 0 ) ;  
 	 p R e c u r - > m _ n   =   _ w t o i ( b u f f ) ;  
 	 G e t D l g I t e m T e x t ( h D l g ,   I D C _ E D I T _ F ,   ( L P W S T R ) b u f f ,   2 0 ) ;  
  
 	 p R e c u r - > m _ f   =   _ w t o f ( b u f f ) ;  
 	 G e t D l g I t e m T e x t ( h D l g ,   I D C _ E D I T _ C ,   ( L P W S T R ) b u f f ,   2 0 ) ;  
 	 p R e c u r - > m _ c   =   _ w t o f ( b u f f ) ;  
 	 G e t D l g I t e m T e x t ( h D l g ,   I D C _ E D I T _ N S A T ,   ( L P W S T R ) b u f f ,   2 0 ) ;  
 	 p R e c u r - > m _ n s a t   =   _ w t o i ( b u f f ) ;  
 }  
 v o i d   H a n d l e O n I n i t D i a l o g ( H W N D   h D l g )  
 {  
 	 c h a r   b u f f [ 2 0 ] ;   w c h a r _ t   r e s [ 2 0 ] ;  
 	 s i z e _ t   o u t S i z e ;  
 	 S e t D l g I t e m I n t ( h D l g ,   I D C _ E D I T _ N ,   p R e c u r - > m _ n ,   T R U E ) ;  
 	 S e t D l g I t e m I n t ( h D l g ,   I D C _ E D I T _ N S A T ,   p R e c u r - > m _ n s a t ,   T R U E ) ;  
  
 	 s p r i n t f _ s ( b u f f ,   " % f " ,   p R e c u r - > m _ f ) ;  
 	 m b s t o w c s _ s ( & o u t S i z e ,   r e s ,   b u f f ,   s t r l e n ( b u f f )   +   1 ) ;  
 	 S e t D l g I t e m T e x t ( h D l g ,   I D C _ E D I T _ F ,   r e s ) ;  
  
 	 s p r i n t f _ s ( b u f f ,   " % f " ,   p R e c u r - > m _ c ) ;  
 	 m b s t o w c s _ s ( & o u t S i z e ,   r e s ,   b u f f ,   s t r l e n ( b u f f )   +   1 ) ;  
 	 S e t D l g I t e m T e x t ( h D l g ,   I D C _ E D I T _ C ,   r e s ) ;  
 }  
  
 v o i d   C i r c l e s ( H D C   h d c ,   d o u b l e   x ,   d o u b l e   y ,   d o u b l e   r ,   i n t   n )   {  
 	 i n t   n l   =   n   -   1 ,   i ;  
 	 d o u b l e   f r   =   p R e c u r - > m _ f * r ;  
 	 i f   ( n - -   >   0 )   {  
 	 	 C i r c l e   c i r ( x ,   y ,   r ) ;  
 	 	 c i r . D r a w C i r c l e ( h d c ) ;  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   p R e c u r - > m _ n s a t ;   i + + )   {  
 	 	 	 C i r c l e s ( h d c ,   x   +   r   *   p R e c u r - > m _ c c o s [ i ] ,  
 	 	 	 	 y   +   r   *   p R e c u r - > m _ c s i n [ i ] ,   f r ,   n l ) ;  
 	 	 }  
 	 }  
 }  
 v o i d   D r a w C i r c l e s ( H D C   h d c ,   i n t   w ,   i n t   h ,   i n t   n ,   d o u b l e   c )   {  
 	 d o u b l e   p   =   1 . ,   R ,   t h e t a ,   r ;  
 	 i n t   m i n W H   =   ( w   >   h )   ?   h   :   w ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + ) p   * =   p R e c u r - > m _ f ;  
 	 t h e t a   =   2   *   3 . 1 4   /   p R e c u r - > m _ n s a t ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   p R e c u r - > m _ n s a t ;   + + i )   {  
 	 	 p R e c u r - > m _ c c o s [ i ]   =   c   *   c o s ( i * t h e t a ) ;  
 	 	 p R e c u r - > m _ c s i n [ i ]   =   c   *   s i n ( i * t h e t a ) ;  
 	 }  
 	 R   =   m i n W H   *   ( 1   -   p R e c u r - > m _ f )   /   ( 1   -   p ) ;  
 	 r   =   R   /   c ;  
 	 C i r c l e s ( h d c ,   w ,   h ,   r ,   n ) ;  
 } 