яю 
 / /   C o n t r o l s D l g . h   :   h e a d e r   f i l e  
 / /  
  
 # p r a g m a   o n c e  
 # i n c l u d e   " a f x c m n . h "  
 # i n c l u d e   " C P i c t . h "  
 # i n c l u d e   " a f x w i n . h "  
  
 / /   C C o n t r o l s D l g   d i a l o g  
 c l a s s   C C o n t r o l s D l g   :   p u b l i c   C D i a l o g  
 {  
 / /   C o n s t r u c t i o n  
 p u b l i c :  
 	 C C o n t r o l s D l g ( C W n d *   p P a r e n t   =   N U L L ) ; 	 / /   s t a n d a r d   c o n s t r u c t o r  
  
 / /   D i a l o g   D a t a  
 # i f d e f   A F X _ D E S I G N _ T I M E  
 	 e n u m   {   I D D   =   I D D _ C O N T R O L S _ D I A L O G   } ;  
 # e n d i f  
  
 	 p r o t e c t e d :  
 	 v i r t u a l   v o i d   D o D a t a E x c h a n g e ( C D a t a E x c h a n g e *   p D X ) ; 	 / /   D D X / D D V   s u p p o r t  
  
  
 / /   I m p l e m e n t a t i o n  
 p r o t e c t e d :  
 	 H I C O N   m _ h I c o n ;  
  
 	 / /   G e n e r a t e d   m e s s a g e   m a p   f u n c t i o n s  
 	 v i r t u a l   B O O L   O n I n i t D i a l o g ( ) ;  
 	 a f x _ m s g   v o i d   O n S y s C o m m a n d ( U I N T   n I D ,   L P A R A M   l P a r a m ) ;  
 	 a f x _ m s g   v o i d   O n P a i n t ( ) ;  
 	 a f x _ m s g   H C U R S O R   O n Q u e r y D r a g I c o n ( ) ;  
 	 D E C L A R E _ M E S S A G E _ M A P ( )  
 p u b l i c :  
 	 C S l i d e r C t r l   m _ S l i d e r ;      
 	 C P i c t   m _ P i c t ;  
 	 a f x _ m s g   v o i d   O n H S c r o l l ( U I N T   n S B C o d e ,   U I N T   n P o s ,   C S c r o l l B a r *   p S c r o l l B a r ) ;  
 } ;  
 