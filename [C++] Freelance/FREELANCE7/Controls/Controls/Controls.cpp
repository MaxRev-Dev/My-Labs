яю 
 / /   C o n t r o l s . c p p   :   D e f i n e s   t h e   c l a s s   b e h a v i o r s   f o r   t h e   a p p l i c a t i o n .  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
 # i n c l u d e   " C o n t r o l s . h "  
 # i n c l u d e   " C o n t r o l s D l g . h "  
  
 # i f d e f   _ D E B U G  
 # d e f i n e   n e w   D E B U G _ N E W  
 # e n d i f  
  
  
 / /   C C o n t r o l s A p p  
  
 B E G I N _ M E S S A G E _ M A P ( C C o n t r o l s A p p ,   C W i n A p p )  
 	 O N _ C O M M A N D ( I D _ H E L P ,   & C W i n A p p : : O n H e l p )  
 E N D _ M E S S A G E _ M A P ( )  
  
  
 / /   C C o n t r o l s A p p   c o n s t r u c t i o n  
  
 C C o n t r o l s A p p : : C C o n t r o l s A p p ( )  
 {  
 	 / /   s u p p o r t   R e s t a r t   M a n a g e r  
 	 m _ d w R e s t a r t M a n a g e r S u p p o r t F l a g s   =   A F X _ R E S T A R T _ M A N A G E R _ S U P P O R T _ R E S T A R T ;  
  
 	 / /   T O D O :   a d d   c o n s t r u c t i o n   c o d e   h e r e ,  
 	 / /   P l a c e   a l l   s i g n i f i c a n t   i n i t i a l i z a t i o n   i n   I n i t I n s t a n c e  
 }  
  
  
 / /   T h e   o n e   a n d   o n l y   C C o n t r o l s A p p   o b j e c t  
  
 C C o n t r o l s A p p   t h e A p p ;  
  
 / /   C C o n t r o l s A p p   i n i t i a l i z a t i o n  
  
 B O O L   C C o n t r o l s A p p : : I n i t I n s t a n c e ( )  
 {  
 	 / /   I n i t C o m m o n C o n t r o l s E x ( )   i s   r e q u i r e d   o n   W i n d o w s   X P   i f   a n   a p p l i c a t i o n  
 	 / /   m a n i f e s t   s p e c i f i e s   u s e   o f   C o m C t l 3 2 . d l l   v e r s i o n   6   o r   l a t e r   t o   e n a b l e  
 	 / /   v i s u a l   s t y l e s .     O t h e r w i s e ,   a n y   w i n d o w   c r e a t i o n   w i l l   f a i l .  
 	 I N I T C O M M O N C O N T R O L S E X   I n i t C t r l s ;  
 	 I n i t C t r l s . d w S i z e   =   s i z e o f ( I n i t C t r l s ) ;  
 	 / /   S e t   t h i s   t o   i n c l u d e   a l l   t h e   c o m m o n   c o n t r o l   c l a s s e s   y o u   w a n t   t o   u s e  
 	 / /   i n   y o u r   a p p l i c a t i o n .  
 	 I n i t C t r l s . d w I C C   =   I C C _ W I N 9 5 _ C L A S S E S ;  
 	 I n i t C o m m o n C o n t r o l s E x ( & I n i t C t r l s ) ;  
  
 	 C W i n A p p : : I n i t I n s t a n c e ( ) ;  
  
  
 	 A f x E n a b l e C o n t r o l C o n t a i n e r ( ) ;  
  
 	 / /   C r e a t e   t h e   s h e l l   m a n a g e r ,   i n   c a s e   t h e   d i a l o g   c o n t a i n s  
 	 / /   a n y   s h e l l   t r e e   v i e w   o r   s h e l l   l i s t   v i e w   c o n t r o l s .  
 	 C S h e l l M a n a g e r   * p S h e l l M a n a g e r   =   n e w   C S h e l l M a n a g e r ;  
  
 	 / /   A c t i v a t e   " W i n d o w s   N a t i v e "   v i s u a l   m a n a g e r   f o r   e n a b l i n g   t h e m e s   i n   M F C   c o n t r o l s  
 	 C M F C V i s u a l M a n a g e r : : S e t D e f a u l t M a n a g e r ( R U N T I M E _ C L A S S ( C M F C V i s u a l M a n a g e r W i n d o w s ) ) ;  
  
 	 / /   S t a n d a r d   i n i t i a l i z a t i o n  
 	 / /   I f   y o u   a r e   n o t   u s i n g   t h e s e   f e a t u r e s   a n d   w i s h   t o   r e d u c e   t h e   s i z e  
 	 / /   o f   y o u r   f i n a l   e x e c u t a b l e ,   y o u   s h o u l d   r e m o v e   f r o m   t h e   f o l l o w i n g  
 	 / /   t h e   s p e c i f i c   i n i t i a l i z a t i o n   r o u t i n e s   y o u   d o   n o t   n e e d  
 	 / /   C h a n g e   t h e   r e g i s t r y   k e y   u n d e r   w h i c h   o u r   s e t t i n g s   a r e   s t o r e d  
 	 / /   T O D O :   Y o u   s h o u l d   m o d i f y   t h i s   s t r i n g   t o   b e   s o m e t h i n g   a p p r o p r i a t e  
 	 / /   s u c h   a s   t h e   n a m e   o f   y o u r   c o m p a n y   o r   o r g a n i z a t i o n  
 	 S e t R e g i s t r y K e y ( _ T ( " L o c a l   A p p W i z a r d - G e n e r a t e d   A p p l i c a t i o n s " ) ) ;  
  
 	 C C o n t r o l s D l g   d l g ;  
 	 m _ p M a i n W n d   =   & d l g ;  
 	 I N T _ P T R   n R e s p o n s e   =   d l g . D o M o d a l ( ) ;  
 	 i f   ( n R e s p o n s e   = =   I D O K )  
 	 {  
 	 	 / /   T O D O :   P l a c e   c o d e   h e r e   t o   h a n d l e   w h e n   t h e   d i a l o g   i s  
 	 	 / /     d i s m i s s e d   w i t h   O K  
 	 }  
 	 e l s e   i f   ( n R e s p o n s e   = =   I D C A N C E L )  
 	 {  
 	 	 / /   T O D O :   P l a c e   c o d e   h e r e   t o   h a n d l e   w h e n   t h e   d i a l o g   i s  
 	 	 / /     d i s m i s s e d   w i t h   C a n c e l  
 	 }  
 	 e l s e   i f   ( n R e s p o n s e   = =   - 1 )  
 	 {  
 	 	 T R A C E ( t r a c e A p p M s g ,   0 ,   " W a r n i n g :   d i a l o g   c r e a t i o n   f a i l e d ,   s o   a p p l i c a t i o n   i s   t e r m i n a t i n g   u n e x p e c t e d l y . \ n " ) ;  
 	 	 T R A C E ( t r a c e A p p M s g ,   0 ,   " W a r n i n g :   i f   y o u   a r e   u s i n g   M F C   c o n t r o l s   o n   t h e   d i a l o g ,   y o u   c a n n o t   # d e f i n e   _ A F X _ N O _ M F C _ C O N T R O L S _ I N _ D I A L O G S . \ n " ) ;  
 	 }  
  
 	 / /   D e l e t e   t h e   s h e l l   m a n a g e r   c r e a t e d   a b o v e .  
 	 i f   ( p S h e l l M a n a g e r   ! =   N U L L )  
 	 {  
 	 	 d e l e t e   p S h e l l M a n a g e r ;  
 	 }  
  
 # i f   ! d e f i n e d ( _ A F X D L L )   & &   ! d e f i n e d ( _ A F X _ N O _ M F C _ C O N T R O L S _ I N _ D I A L O G S )  
 	 C o n t r o l B a r C l e a n U p ( ) ;  
 # e n d i f  
  
 	 / /   S i n c e   t h e   d i a l o g   h a s   b e e n   c l o s e d ,   r e t u r n   F A L S E   s o   t h a t   w e   e x i t   t h e  
 	 / /     a p p l i c a t i o n ,   r a t h e r   t h a n   s t a r t   t h e   a p p l i c a t i o n ' s   m e s s a g e   p u m p .  
 	 r e t u r n   F A L S E ;  
 }  
  
 