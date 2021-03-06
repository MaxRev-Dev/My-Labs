яю 
 / /   C o n t r o l s D l g . c p p   :   i m p l e m e n t a t i o n   f i l e  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
 # i n c l u d e   " C o n t r o l s . h "  
 # i n c l u d e   " C o n t r o l s D l g . h "  
 # i n c l u d e   " a f x d i a l o g e x . h "  
  
 # i f d e f   _ D E B U G  
 # d e f i n e   n e w   D E B U G _ N E W  
 # e n d i f  
  
  
 / /   C A b o u t D l g   d i a l o g   u s e d   f o r   A p p   A b o u t  
  
 c l a s s   C A b o u t D l g   :   p u b l i c   C D i a l o g E x  
 {  
 p u b l i c :  
 	 C A b o u t D l g ( ) ;  
  
 / /   D i a l o g   D a t a  
 # i f d e f   A F X _ D E S I G N _ T I M E  
 	 e n u m   {   I D D   =   I D D _ A B O U T B O X   } ;  
 # e n d i f  
  
 	 p r o t e c t e d :  
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
 / /   C C o n t r o l s D l g   d i a l o g  
  
  
  
 C C o n t r o l s D l g : : C C o n t r o l s D l g ( C W n d *   p P a r e n t   / * = N U L L * / )  
 	 :   C D i a l o g ( I D D _ C O N T R O L S _ D I A L O G ,   p P a r e n t )  
 {  
 	 m _ h I c o n   =   A f x G e t A p p ( ) - > L o a d I c o n ( I D R _ M A I N F R A M E ) ;  
 }  
  
 v o i d   C C o n t r o l s D l g : : D o D a t a E x c h a n g e ( C D a t a E x c h a n g e *   p D X )  
 {  
 	 C D i a l o g : : D o D a t a E x c h a n g e ( p D X ) ;  
 	 D D X _ C o n t r o l ( p D X ,   I D C _ S L I D E R 1 ,   m _ S l i d e r ) ;  
 	 D D X _ C o n t r o l ( p D X ,   I D C _ P I C T ,   m _ P i c t ) ;  
 }  
  
 B E G I N _ M E S S A G E _ M A P ( C C o n t r o l s D l g ,   C D i a l o g )  
 	 O N _ W M _ S Y S C O M M A N D ( )  
 	 O N _ W M _ P A I N T ( )  
 	 O N _ W M _ Q U E R Y D R A G I C O N ( )  
 	 O N _ W M _ H S C R O L L ( )  
 E N D _ M E S S A G E _ M A P ( )  
  
  
 / /   C C o n t r o l s D l g   m e s s a g e   h a n d l e r s  
  
 B O O L   C C o n t r o l s D l g : : O n I n i t D i a l o g ( )  
 {  
 	 C D i a l o g : : O n I n i t D i a l o g ( ) ;  
  
 	 / /   A d d   " A b o u t . . . "   m e n u   i t e m   t o   s y s t e m   m e n u .  
  
 	 / /   I D M _ A B O U T B O X   m u s t   b e   i n   t h e   s y s t e m   c o m m a n d   r a n g e .  
 	 A S S E R T ( ( I D M _ A B O U T B O X   &   0 x F F F 0 )   = =   I D M _ A B O U T B O X ) ;  
 	 A S S E R T ( I D M _ A B O U T B O X   <   0 x F 0 0 0 ) ;  
  
 	 C M e n u *   p S y s M e n u   =   G e t S y s t e m M e n u ( F A L S E ) ;  
 	 i f   ( p S y s M e n u   ! =   N U L L )  
 	 {  
 	 	 B O O L   b N a m e V a l i d ;  
 	 	 C S t r i n g   s t r A b o u t M e n u ;  
 	 	 b N a m e V a l i d   =   s t r A b o u t M e n u . L o a d S t r i n g ( I D S _ A B O U T B O X ) ;  
 	 	 A S S E R T ( b N a m e V a l i d ) ;  
 	 	 i f   ( ! s t r A b o u t M e n u . I s E m p t y ( ) )  
 	 	 {  
 	 	 	 p S y s M e n u - > A p p e n d M e n u ( M F _ S E P A R A T O R ) ;  
 	 	 	 p S y s M e n u - > A p p e n d M e n u ( M F _ S T R I N G ,   I D M _ A B O U T B O X ,   s t r A b o u t M e n u ) ;  
 	 	 }  
 	 }  
  
 	 / /   S e t   t h e   i c o n   f o r   t h i s   d i a l o g .     T h e   f r a m e w o r k   d o e s   t h i s   a u t o m a t i c a l l y  
 	 / /     w h e n   t h e   a p p l i c a t i o n ' s   m a i n   w i n d o w   i s   n o t   a   d i a l o g  
 	 S e t I c o n ( m _ h I c o n ,   T R U E ) ; 	 	 	 / /   S e t   b i g   i c o n  
 	 S e t I c o n ( m _ h I c o n ,   F A L S E ) ; 	 	 / /   S e t   s m a l l   i c o n  
  
 	 / /   T O D O :   A d d   e x t r a   i n i t i a l i z a t i o n   h e r e  
  
 	 r e t u r n   T R U E ;     / /   r e t u r n   T R U E     u n l e s s   y o u   s e t   t h e   f o c u s   t o   a   c o n t r o l  
 }  
  
 v o i d   C C o n t r o l s D l g : : O n S y s C o m m a n d ( U I N T   n I D ,   L P A R A M   l P a r a m )  
 {  
 	 i f   ( ( n I D   &   0 x F F F 0 )   = =   I D M _ A B O U T B O X )  
 	 {  
 	 	 C A b o u t D l g   d l g A b o u t ;  
 	 	 d l g A b o u t . D o M o d a l ( ) ;  
 	 }  
 	 e l s e  
 	 {  
 	 	 C D i a l o g : : O n S y s C o m m a n d ( n I D ,   l P a r a m ) ;  
 	 }  
 }  
  
 / /   I f   y o u   a d d   a   m i n i m i z e   b u t t o n   t o   y o u r   d i a l o g ,   y o u   w i l l   n e e d   t h e   c o d e   b e l o w  
 / /     t o   d r a w   t h e   i c o n .     F o r   M F C   a p p l i c a t i o n s   u s i n g   t h e   d o c u m e n t / v i e w   m o d e l ,  
 / /     t h i s   i s   a u t o m a t i c a l l y   d o n e   f o r   y o u   b y   t h e   f r a m e w o r k .  
  
 v o i d   C C o n t r o l s D l g : : O n P a i n t ( )  
 {  
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
 	 	 C D i a l o g : : O n P a i n t ( ) ;  
 	 }  
 }  
  
 / /   T h e   s y s t e m   c a l l s   t h i s   f u n c t i o n   t o   o b t a i n   t h e   c u r s o r   t o   d i s p l a y   w h i l e   t h e   u s e r   d r a g s  
 / /     t h e   m i n i m i z e d   w i n d o w .  
 H C U R S O R   C C o n t r o l s D l g : : O n Q u e r y D r a g I c o n ( )  
 {  
 	 r e t u r n   s t a t i c _ c a s t < H C U R S O R > ( m _ h I c o n ) ;  
 }  
  
  
  
 i n t   e l l i p s e O f f s e t   =   0 ;  
 v o i d   C C o n t r o l s D l g : : O n H S c r o l l ( U I N T   n S B C o d e ,   U I N T   n P o s ,   C S c r o l l B a r *   p S c r o l l B a r )  
 {  
 	 C S l i d e r C t r l   * p S l i d e r   =   ( C S l i d e r C t r l   * ) p S c r o l l B a r ;  
 	 e l l i p s e O f f s e t   =   p S l i d e r - > G e t P o s ( ) ;  
 	 m _ P i c t . I n v a l i d a t e R e c t ( N U L L ) ;  
  
 	 C D i a l o g : : O n H S c r o l l ( n S B C o d e ,   n P o s ,   p S c r o l l B a r ) ;  
 }  
 