/********************************************************
* This script creates the database named my_guitar_shop 
*********************************************************/

DROP DATABASE IF EXISTS cs431_music_store;
CREATE DATABASE cs431_music_store;
USE cs431_music_store;

-- create the tables for the database
CREATE TABLE categories (
  category_id        INT            PRIMARY KEY   AUTO_INCREMENT,
  category_name      VARCHAR(255)   NOT NULL      UNIQUE
);

CREATE TABLE instruments (
  instrument_id         INT            PRIMARY KEY   AUTO_INCREMENT,
  category_id        INT            NOT NULL,
  instrument_code       VARCHAR(10)    NOT NULL      UNIQUE,
  instrument_name       VARCHAR(255)   NOT NULL,
  description        TEXT           NOT NULL,
  list_price         DECIMAL(10,2)  NOT NULL,
  discount_percent   DECIMAL(10,2)  NOT NULL      DEFAULT 0.00,
  date_added         DATETIME                     DEFAULT NULL,
  CONSTRAINT instruments_fk_categories
    FOREIGN KEY (category_id)
    REFERENCES categories (category_id)
);

CREATE TABLE musicians (
  musician_id           INT            PRIMARY KEY   AUTO_INCREMENT,
  email_address         VARCHAR(255)   NOT NULL      UNIQUE,
  password              VARCHAR(60)    NOT NULL,
  first_name            VARCHAR(60)    NOT NULL,
  last_name             VARCHAR(60)    NOT NULL,
  shipping_address_id   INT                          DEFAULT NULL,
  billing_address_id    INT                          DEFAULT NULL
);

CREATE TABLE addresses (
  address_id         INT            PRIMARY KEY   AUTO_INCREMENT,
  musician_id        INT            NOT NULL,
  line1              VARCHAR(60)    NOT NULL,
  line2              VARCHAR(60)                  DEFAULT NULL,
  city               VARCHAR(40)    NOT NULL,
  state              VARCHAR(2)     NOT NULL,
  zip_code           VARCHAR(10)    NOT NULL,
  phone              VARCHAR(12)    NOT NULL,
  disabled           TINYINT(1)     NOT NULL      DEFAULT 0,
  CONSTRAINT addresses_fk_musicians
    FOREIGN KEY (musician_id)
    REFERENCES musicians (musician_id)
);

CREATE TABLE orders (
  order_id           INT            PRIMARY KEY  AUTO_INCREMENT,
  musician_id        INT            NOT NULL,
  order_date         DATETIME       NOT NULL,
  ship_amount        DECIMAL(10,2)  NOT NULL,
  tax_amount         DECIMAL(10,2)  NOT NULL,
  ship_date          DATETIME                    DEFAULT NULL,
  ship_address_id    INT            NOT NULL,
  card_type          VARCHAR(50)    NOT NULL,
  card_number        CHAR(16)       NOT NULL,
  card_expires       CHAR(7)        NOT NULL,
  billing_address_id  INT           NOT NULL,
  CONSTRAINT orders_fk_musicians
    FOREIGN KEY (musician_id)
    REFERENCES musicians (musician_id)
);

CREATE TABLE order_instruments (
  item_id            INT            PRIMARY KEY  AUTO_INCREMENT,
  order_id           INT            NOT NULL,
  instrument_id         INT            NOT NULL,
  item_price         DECIMAL(10,2)  NOT NULL,
  discount_amount    DECIMAL(10,2)  NOT NULL,
  quantity           INT            NOT NULL,
  CONSTRAINT order_instruments_fk_orders
    FOREIGN KEY (order_id)
    REFERENCES orders (order_id), 
  CONSTRAINT order_instruments_fk_instruments
    FOREIGN KEY (instrument_id)
    REFERENCES instruments (instrument_id)
);

CREATE TABLE administrators (
  admin_id           INT            PRIMARY KEY   AUTO_INCREMENT,
  email_address      VARCHAR(255)   NOT NULL,
  password           VARCHAR(255)   NOT NULL,
  first_name         VARCHAR(255)   NOT NULL,
  last_name          VARCHAR(255)   NOT NULL
);

-- Insert data into the tables
INSERT INTO categories (category_id, category_name) VALUES
(1, 'Guitars'),
(2, 'Piano'),
(3, 'Saxophone'), 
(4, 'Keyboards');

INSERT INTO instruments (instrument_id, category_id, instrument_code, instrument_name, description, list_price, discount_percent, date_added) VALUES
(1, 1, 'strat', 'Fender Stratocaster', 'The Fender Stratocaster is the electric guitar design that changed the world. New features include a tinted neck, parchment pickguard and control knobs, and a ''70s-style logo. Includes select alder body, 21-fret maple neck with your choice of a rosewood or maple fretboard, 3 single-coil pickups, vintage-style tremolo, and die-cast tuning keys. This guitar features a thicker bridge block for increased sustain and a more stable point of contact with the strings. At this low price, why play anything but the real thing?\r\n\r\nFeatures:\r\n\r\n* New features:\r\n* Thicker bridge block\r\n* 3-ply parchment pick guard\r\n* Tinted neck', '699.00', '30.00', '2017-10-30 09:32:40'),
(2, 1, 'les_paul', 'Gibson Les Paul', 'This Les Paul guitar offers a carved top and humbucking pickups. It has a simple yet elegant design. Cutting-yet-rich tone?the hallmark of the Les Paul?pours out of the 490R and 498T Alnico II magnet humbucker pickups, which are mounted on a carved maple top with a mahogany back. The faded finish models are equipped with BurstBucker Pro pickups and a mahogany top. This guitar includes a Gibson hardshell case (Faded and satin finish models come with a gig bag) and a limited lifetime warranty.\r\n\r\nFeatures:\r\n\r\n* Carved maple top and mahogany back (Mahogany top on faded finish models)\r\n* Mahogany neck, ''59 Rounded Les Paul\r\n* Rosewood fingerboard (Ebony on Alpine white)\r\n* Tune-O-Matic bridge with stopbar\r\n* Chrome or gold hardware\r\n* 490R and 498T Alnico 2 magnet humbucker pickups (BurstBucker Pro on faded finish models)\r\n* 2 volume and 2 tone knobs, 3-way switch', '1199.00', '30.00', '2017-12-05 16:33:13'),
(3, 1, 'sg', 'Gibson SG', 'This Gibson SG electric guitar takes the best of the ''62 original and adds the longer and sturdier neck joint of the late ''60s models. All the classic features you''d expect from a historic guitar. Hot humbuckers go from rich, sweet lightning to warm, tingling waves of sustain. A silky-fast rosewood fretboard plays like a dream. The original-style beveled mahogany body looks like a million bucks. Plus, Tune-O-Matic bridge and chrome hardware. Limited lifetime warranty. Includes hardshell case.\r\n\r\nFeatures:\r\n\r\n* Double-cutaway beveled mahogany body\r\n* Set mahogany neck with rounded ''50s profile\r\n* Bound rosewood fingerboard with trapezoid inlays\r\n* Tune-O-Matic bridge with stopbar tailpiece\r\n* Chrome hardware\r\n* 490R humbucker in the neck position\r\n* 498T humbucker in the bridge position\r\n* 2 volume knobs, 2 tone knobs, 3-way switch\r\n* 24-3/4" scale', '2517.00', '52.00', '2018-02-04 11:04:31'),
(4, 2, 'cdp_s350', 'Casio CDP-S350 Compact Digital Piano Black', 'The reimagined CDP-S350 delivers unprecedented piano authenticity in a conveniently sized package that fits any room. \r\n\With over 700 brilliant new tones and an enhanced graded hammer piano action across all 88 keys,the CDP-S350 draws you into a world of sound exploration with a realistic feel that is both engaging and inspiring. \r\n\It is lightweight and smaller than other competing models with the ability to run off battery power,\r\n\\r\n\ ', '489.99', '38.00', '2018-06-01 11:12:59'),
(5, 2, 'washburn', 'Williams Allegro III Digital Piano Black 88 Key', '
The Williams Allegro III is an 88 weighted-key digital piano with superior sounds and breakthrough features that are ideal for the advancing 
student or the professional player who appreciates nuanced key control and high-quality sound. Taken from the Williams Custom Sound Library,
 it features 10 high-resolution sounds including Pianos, Electric Pianos, Organs, Strings and Bass, recorded using the finest instruments in
 the world with full dynamic ranges. The newly improved, weighted piano-action keyboard, allows for quick, responsive feel and control over 
 the entire key range. The dual-driver speakers deliver all those lush tones with outstanding clarity and volume. The Allegro III can run on batteries or with the included AC power supply.', '299.00', '0.00', '2018-07-30 13:58:35'),
(6, 2, 'dgx660', 'Yamaha DGX-660 88-Key Portable Grand  Black', 'The Pure CF Sound Engine is the result of years of piano-making history combined
 with state-of-the-art sampling technology and piano expertise. Yamaha is the industry leader in digital piano technology, and you can hear
 this in the Voices that utilize the Pure CF piano sample. The sound of the renowned Yamaha CFIIIS  concert grand piano is faithfully reproduced, allowing for incredible dynamics and expressiveness, making the DGX-660 worthy of the Yamaha name
 ', '415.00', '39.00', '2018-07-30 14:12:41'),
(7, 3, 'eas100', 'Etude EAS-100 Student Alto Saxophone Lacquer',' 	
Made out of fine metals for superior tone production, the Etude EAS-100 is the perfect instrument for starting out on the alto saxophone. The keywork, pads, and adjustment all work together to make tone production easier, more consistent, and stronger. And the bell brace and construction help make it as durable as possible. Includes case, mouthpiece, cap, and ligature  ', '799.99', '30.00', '2018-06-01 11:29:35'),
(8, 3, 'jbs1000', 'Jupiter JBS1000 Deluxe Baritone Saxophone', 'A great buy for a first baritone or for the doubler, the JBS1000 Deluxe Baritone Saxophone has all of the features you will need. A low A key, tilting Bb spatula key and Jupiter''s legendary tone come standard. Gold lacquer finish.', '499.99', '25.00', '2018-07-30 14:18:33'),
(9, 4, 'fantom6', 'Roland FANTOM-6 Music Workstation Keyboard', 'The Roland FANTOM-6 Music Workstation Keyboard is made for rapid production
 and expressive performance. Inspiring onboard production tools and deep computer integration fuel an experience that feels intuitive, 
 natural, and full of possibilities. The expandable sound engine delivers Roland''s best electronic and acoustic sounds, with the depth and
 control to combine and shape them in exciting new ways. And it''s built from premium materials, with a purposeful design, and the best 61-, 76-, and 88-note keyboards Roland have ever made.', '699.99', '30.00', '2018-07-30 12:46:40'),
(10, 4, 'PSR-SX900', 'Yamaha PSR-SX900 61-Key High-Level Arranger Keyboard', ' The PSR-SX900 features content from the flagship, Genos Digital Workstation. This next-level content sounds incredible through the newly designed, bi-amped speaker system with wide stereo audio field. Navigate with ease using the 7" TFT touch screen, or setup the assignable buttons to access your preferred functions. Other new features include a joystick controller, Chord Looper, new keyboard action inherited from Yamaha synthesizers, new insertion effect structure, Style section reset, 
and more. The PSR-SX900 helps make music easier and sound better than ever.', '799.99', '15.00', '2018-07-30 13:14:15');

INSERT INTO musicians (musician_id, email_address, password, first_name, last_name, shipping_address_id, billing_address_id) VALUES
(1, 'allan.sherwood@yahoo.com', '650215acec746f0e32bdfff387439eefc1358737', 'Allan', 'Sherwood', 1, 2),
(2, 'barryz@gmail.com', '3f563468d42a448cb1e56924529f6e7bbe529cc7', 'Barry', 'Zimmer', 3, 3),
(3, 'christineb@solarone.com', 'ed19f5c0833094026a2f1e9e6f08a35d26037066', 'Christine', 'Brown', 4, 4),
(4, 'david.goldstein@hotmail.com', 'b444ac06613fc8d63795be9ad0beaf55011936ac', 'David', 'Goldstein', 5, 6),
(5, 'erinv@gmail.com', '109f4b3c50d7b0df729d299bc6f8e9ef9066971f', 'Erin', 'Valentino', 7, 7),
(6, 'frankwilson@sbcglobal.net', '3ebfa301dc59196f18593c45e519287a23297589', 'Frank Lee', 'Wilson', 8, 8),
(7, 'gary_hernandez@yahoo.com', '1ff2b3704aede04eecb51e50ca698efd50a1379b', 'Gary', 'Hernandez', 9, 10),
(8, 'heatheresway@mac.com', '911ddc3b8f9a13b5499b6bc4638a2b4f3f68bf23', 'Heather', 'Esway', 11, 12);

INSERT INTO addresses (address_id, musician_id, line1, line2, city, state, zip_code, phone, disabled) VALUES
(1, 1, '100 East Ridgewood Ave.', '', 'Paramus', 'NJ', '07652', '201-653-4472', 0),
(2, 1, '21 Rosewood Rd.', '', 'Woodcliff Lake', 'NJ', '07677', '201-653-4472', 0),
(3, 2, '16285 Wendell St.', '', 'Omaha', 'NE', '68135', '402-896-2576', 0),
(4, 3, '19270 NW Cornell Rd.', '', 'Beaverton', 'OR', '97006', '503-654-1291', 0),
(5, 4, '186 Vermont St.', 'Apt. 2', 'San Francisco', 'CA', '94110', '415-292-6651', 0),
(6, 4, '1374 46th Ave.', '', 'San Francisco', 'CA', '94129', '415-292-6651', 0),
(7, 5, '6982 Palm Ave.', '', 'Fresno', 'CA', '93711', '559-431-2398', 0),
(8, 6, '23 Mountain View St.', '', 'Denver', 'CO', '80208', '303-912-3852', 0),
(9, 7, '7361 N. 41st St.', 'Apt. B', 'New York', 'NY', '10012', '212-335-2093', 0),
(10, 7, '3829 Broadway Ave.', 'Suite 2', 'New York', 'NY', '10012', '212-239-1208', 0),
(11, 8, '2381 Buena Vista St.', '', 'Los Angeles', 'CA', '90023', '213-772-5033', 0),
(12, 8, '291 W. Hollywood Blvd.', '', 'Los Angeles', 'CA', '90024', '213-391-2938', 0);

INSERT INTO orders (order_id, musician_id, order_date, ship_amount, tax_amount, ship_date, ship_address_id, card_type, card_number, card_expires, billing_address_id) VALUES
(1, 1, '2018-03-28 09:40:28', '5.00', '32.32', '2018-03-30 15:32:51', 1, 'Visa', '4111111111111111', '04/2020', 2),
(2, 2, '2018-03-28 11:23:20', '5.00', '0.00', '2018-03-29 12:52:14', 3, 'Visa', '4012888888881881', '08/2019', 3),
(3, 1, '2018-03-29 09:44:58', '10.00', '89.92', '2018-03-31 9:11:41', 1, 'Visa', '4111111111111111', '04/2017', 2),
(4, 3, '2018-03-30 15:22:31', '5.00', '0.00', '2018-04-03 16:32:21', 4, 'American Express', '378282246310005', '04/2016', 4),
(5, 4, '2018-03-31 05:43:11', '5.00', '0.00', '2018-04-02 14:21:12', 5, 'Visa', '4111111111111111', '04/2019', 6),
(6, 5, '2018-03-31 18:37:22', '5.00', '0.00', NULL, 7, 'Discover', '6011111111111117', '04/2019', 7),
(7, 6, '2018-04-01 23:11:12', '15.00', '0.00', '2018-04-03 10:21:35', 8, 'MasterCard', '5555555555554444', '04/2019', 8),
(8, 7, '2018-04-02 11:26:38', '5.00', '0.00', NULL, 9, 'Visa', '4012888888881881', '04/2019', 10),
(9, 4, '2018-04-03 12:22:31', '5.00', '0.00', NULL, 5, 'Visa', '4111111111111111', '04/2019', 6);

INSERT INTO order_instruments (item_id, order_id, instrument_id, item_price, discount_amount, quantity) VALUES
(1, 1, 2, '1199.00', '359.70', 1),
(2, 2, 4, '489.99', '186.20', 1),
(3, 3, 3, '2517.00', '1308.84', 1),
(4, 3, 6, '415.00', '161.85', 1),
(5, 4, 2, '1199.00', '359.70', 2),
(6, 5, 5, '299.00', '0.00', 1),
(7, 6, 5, '299.00', '0.00', 1),
(8, 7, 1, '699.00', '209.70', 1),
(9, 7, 7, '799.99', '240.00', 1),
(10, 7, 9, '699.99', '210.00', 1),
(11, 8, 10, '799.99', '120.00', 1),
(12, 9, 1, '699.00', '209.70', 1);

INSERT INTO administrators (admin_id, email_address, password, first_name, last_name) VALUES
(1, 'admin@music_store.com', '6a718fbd768c2378b511f8249b54897f940e9022', 'Admin', 'User'),
(2, 'joel@music_store.com', '971e95957d3b74d70d79c20c94e9cd91b85f7aae', 'Indira', 'Yellapragada'),
(3, 'mike@music_store.com', '3f2975c819cefc686282456aeae3a137bf896ee8', 'Joel', 'Murach');

-- Create a user named mgs_user
CREATE USER IF NOT EXISTS mgs_user@localhost
IDENTIFIED BY 'pa55word';

-- Grant privileges to that user
GRANT SELECT, INSERT, UPDATE, DELETE
ON mgs.*
TO mgs_user@localhost;