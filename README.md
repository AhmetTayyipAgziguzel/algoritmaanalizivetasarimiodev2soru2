# algoritmaanalizivetasarimiodev2soru2

HORSPOOL ALGORİTHM

Algoritmanın Amacı



Bu program, Boyer-Moore-Horspool algoritmasını kullanarak verilen bir metin dosyasında belirli bir kelime grubunun kaç kez geçtiğini bulmayı amaçlamaktadır. Program, dosya adını, kelime grubunu ve kelime sayacını tanımlar, sonra metin dosyasını satır satır okur ve her satırda kelime grubunu arar. Bulunan kelime sayısını belirtilen kelime sayacına ekler ve sonunda her kelime grubu için kaç kez bulunduğunu yazdırır.


Algoritma Ne İçin Kullanılır veya Kullanılabilir



Bu algoritma, bir metin belgesi veya metin verisi içinde belirli bir kelime grubunun kaç kez geçtiğini bulmak için kullanılabilir. Özellikle büyük metin verilerinde, manuel olarak kelime sayımı yapmak zor ve zaman alıcı olabilir. Bu nedenle, Boyer-Moore-Horspool algoritması gibi otomatik arama algoritmaları, metin içindeki belirli kelime gruplarını hızlı ve doğru bir şekilde saymak için kullanılabilir. Bu tür algoritmalar, metin madenciliği, bilgi arama ve doğal dil işleme gibi alanlarda yaygın olarak kullanılır. Ayrıca, bir kelimenin metin içindeki tüm yerlerini veya benzer kelime gruplarını bulmak için de kullanılabilir.


Algoritmanın Çalışma Şekli



Boyer-Moore-Horspool algoritması, bir metin belgesinde belirli bir kelime grubunun sayısını bulmak için kullanılan bir arama algoritmasıdır. Algoritmanın çalışma şekli aşağıdaki adımlarla açıklanabilir:
1.	Kelime grubunu tersine çevirin ve son karakter hariç her karakter için bir kaydırma tablosu oluşturun. Bu tablo, belirli bir karakterle eşleştiğinde ne kadar kaydırma yapılacağını belirler.
2.	Metin belgesinde, kelime grubunun uzunluğu kadar bir pencere oluşturun.
3.	Pencereyi kelime grubuyla karşılaştırın. Eğer eşleşmezse, kaydırma tablosundan alınan değere göre pencereyi kaydırın.
4.	Eğer pencere kelime grubuyla eşleşirse, bir eşleşme bulunduğunu ve sayacı artırmanız gerektiğini belirtin.
5.	Pencereyi kaydırın ve 3. adımdan devam edin.
6.	Metin belgesinin sonuna gelinceye kadar 3-5 adımlarını tekrarlayın.
7.	Sayacı döndürün ve kelime grubunun belirtilen metin belgesinde kaç kez bulunduğunu hesaplayın.
Bu algoritma, kelime grubunu tersine çevirerek ve kaydırma tablosunu kullanarak, arama işlemini hızlandırır. Ayrıca, metnin sonuna kadar tüm eşleşmeleri bulmaz, sadece belirli bir pencere içinde arama yapar, bu da algoritmanın çalışma süresini azaltır.

Algoritmanın Çalışma Zamanı Analizi



Bu algoritmanın çalışma zamanı analizi aşağıdaki gibidir:

•	En iyi durum: Kelime grubu metinde hiç geçmiyorsa, algoritma sadece dosyanın tamamını bir kez okuyacak ve her kelime grubu için horspool_search fonksiyonunu çağıracaktır. Bu nedenle, en iyi durumda algoritmanın çalışma zamanı O(n), n dosyanın karakter sayısıdır.

•	En kötü durum: Algoritma, kelime grubu metinde çok sık geçiyorsa, horspool_search fonksiyonu bu kelime grubu için tüm olası konumları kontrol etmek zorunda kalacaktır. Bu durumda, horspool_search fonksiyonu O(mn) zamanında çalışacak, burada m kelime grubunun uzunluğudur. Her kelime grubu için fonksiyon çağırdığımızda, bu işlemi 5 kez yapacağız, bu nedenle en kötü durumda algoritmanın çalışma zamanı O(5mn) veya sadece O(mn) olacaktır.

•	Ortalama durum: Genellikle, metindeki kelime gruplarının sayısı dosya boyutuna göre sınırlıdır, bu nedenle, ortalamada, algoritma birkaç kez horspool_search fonksiyonunu çağıracak ve her biri O(mn) zamanında çalışacaktır. Bu nedenle, algoritmanın ortalama çalışma zamanı O(kmn) olacaktır, burada k kelime gruplarının sayısıdır.


