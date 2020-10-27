CREATE TABLE [dbo].[konferentsiyi]
(
	[id_konferentsiyi] INT NOT NULL PRIMARY KEY IDENTITY, 
    [id_spivrobitnyky] NCHAR(11) NULL, 
    [nazva_konfereftsiyi] VARCHAR(MAX) NULL, 
    [data_pochatku] DATE NULL, 
    [data_zakinchennya] DATE NULL
)
