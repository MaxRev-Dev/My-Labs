яю# i n c l u d e   " R e c i p e . h "  
 / /   B o o k O f R e c i p e s D l g . h   :   h e a d e r   f i l e  
 / /  
  
 # p r a g m a   o n c e  
  
  
 / /   C B o o k O f R e c i p e s D l g   d i a l o g  
 c l a s s   C B o o k O f R e c i p e s D l g   :   p u b l i c   C D H t m l D i a l o g  
 {  
 / /   C o n s t r u c t i o n  
 p u b l i c :  
 	 C B o o k O f R e c i p e s D l g ( C W n d *   p P a r e n t   =   n u l l p t r ) ; 	 / /   s t a n d a r d   c o n s t r u c t o r  
  
 / /   D i a l o g   D a t a  
 # i f d e f   A F X _ D E S I G N _ T I M E  
 	 e n u m   {   I D D   =   I D D _ B O O K O F R E C I P E S _ D I A L O G ,   I D H   =   I D R _ H T M L _ B O O K O F R E C I P E S _ D I A L O G   } ;  
 # e n d i f  
  
 	 p r o t e c t e d :  
 	 v i r t u a l   v o i d   D o D a t a E x c h a n g e ( C D a t a E x c h a n g e *   p D X ) ; 	 / /   D D X / D D V   s u p p o r t  
 	    
 	 H R E S U L T   O n N e x t R e c i p e ( I H T M L E l e m e n t   * p E l e m e n t ) ;  
 	 H R E S U L T   O n P r e v R e c i p e ( I H T M L E l e m e n t   * p E l e m e n t ) ;  
 	 H R E S U L T   O n T o g g l e B t n ( I H T M L E l e m e n t   * p E l e m e n t ) ;    
 	 H R E S U L T   E v a l S c r i p t ( A T L : : C C o m P t r < I H T M L D o c u m e n t 2 >   d o c ,   w s t r i n g   c o n t e n t ) ;    
 	 H R E S U L T   O n R e t r y B t n ( I H T M L E l e m e n t   * ) ;    
 	 H R E S U L T   S e t E l e m I n n e r ( w s t r i n g   i d ,   w s t r i n g   i n n e r H t m l ) ;  
 	 v o i d   S e t R e c i p e W i t h I n d e x ( i n t   * i ) ;    
  
 / /   I m p l e m e n t a t i o n  
 p r o t e c t e d :  
 	 H I C O N   m _ h I c o n ;  
 	 R e c i p e F e t c h   c o n t a i n e r ;  
 	 R e c i p e   s e l e c t e d R e c i p e ;  
 	 / /   G e n e r a t e d   m e s s a g e   m a p   f u n c t i o n s  
 	 v i r t u a l   B O O L   O n I n i t D i a l o g ( ) ;  
 	 a f x _ m s g   v o i d   O n S y s C o m m a n d ( U I N T   n I D ,   L P A R A M   l P a r a m ) ;  
 	 a f x _ m s g   v o i d   O n P a i n t ( ) ;  
 	 a f x _ m s g   H C U R S O R   O n Q u e r y D r a g I c o n ( ) ;  
 	 D E C L A R E _ M E S S A G E _ M A P ( )  
 	 D E C L A R E _ D H T M L _ E V E N T _ M A P ( )  
 p u b l i c :  
 	 a f x _ m s g   v o i d   O n A b o u t ( ) ;    
 	 a f x _ m s g   i n t   O n C r e a t e ( L P C R E A T E S T R U C T   l p C r e a t e S t r u c t ) ;    
 	 v o i d   O n D o c u m e n t C o m p l e t e ( L P D I S P A T C H   p D i s p ,   L P C T S T R   s z U r l ) ;    
 } ;  
 