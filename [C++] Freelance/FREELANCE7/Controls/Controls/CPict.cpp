яю/ /   C P i c t . c p p   :   i m p l e m e n t a t i o n   f i l e  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
 # i n c l u d e   " C o n t r o l s . h "  
 # i n c l u d e   " C P i c t . h "  
  
  
 / /   C P i c t  
  
 I M P L E M E N T _ D Y N A M I C ( C P i c t ,   C S t a t i c )  
  
 C P i c t : : C P i c t ( )  
 {  
  
 }  
  
 C P i c t : : ~ C P i c t ( )  
 {  
 }  
  
  
 B E G I N _ M E S S A G E _ M A P ( C P i c t ,   C S t a t i c )  
 	 O N _ W M _ P A I N T ( )  
 	 O N _ W M _ H S C R O L L ( )  
 E N D _ M E S S A G E _ M A P ( )  
  
  
  
 / /   C P i c t   m e s s a g e   h a n d l e r s  
  
  
  
 e x t e r n   i n t   e l l i p s e O f f s e t ;  
 v o i d   C P i c t : : O n P a i n t ( )  
 {  
 	 C P a i n t D C   d c ( t h i s ) ;   / /   d e v i c e   c o n t e x t   f o r   p a i n t i n g  
 	 	 	 	 	       / /   T O D O :   A d d   y o u r   m e s s a g e   h a n d l e r   c o d e   h e r e  
 	 	 	 	 	       / /   D o   n o t   c a l l   C S t a t i c : : O n P a i n t ( )   f o r   p a i n t i n g   m e s s a g e s  
 	 R E C T   r t ;  
 	 G e t W i n d o w R e c t ( & r t ) ;  
 	 O f f s e t R e c t ( & r t ,   - r t . l e f t ,   - r t . t o p ) ;  
 	 C B r u s h   b r u s h W ( R G B ( 2 5 5 ,   2 5 5 ,   2 5 5 ) ) ;  
 	 d c . F i l l R e c t ( & r t ,   & b r u s h W ) ;  
 	 R E C T   e l l i p s e R e c t   =   r t ;  
 	 e l l i p s e R e c t . l e f t   + =   e l l i p s e O f f s e t ;  
 	 e l l i p s e R e c t . t o p   + =   e l l i p s e O f f s e t ;  
 	 e l l i p s e R e c t . r i g h t   - =   e l l i p s e O f f s e t ;  
 	 e l l i p s e R e c t . b o t t o m   - =   e l l i p s e O f f s e t ;  
 	 d c . E l l i p s e ( & e l l i p s e R e c t ) ;  
 }  
   