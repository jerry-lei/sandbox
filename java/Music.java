import java.util.*;

public class Music{
  public static void main(String[] args){
    MusicList ml = new MusicList();
    ml.add(new Song("Riptide", "Vance Joy"));
    ml.add(new Song("Oceans", "Seafret"));
    ml.add(new Song("Angela", "The Lumineers"));
    ml.add(new Song("White Lie", "The Lumineers"));
    ml.add(new Song("Charlie Boy", "The Lumineers"));
    ml.add(new Song("Charlie Boy", "The Lumineers"));
    ml.add(new Song("Charlie Boy", "The Lumineers"));
    ml.add(new Song("Charlie Boy", "The Lumineers"));
    ml.add(new Song("Charlie Boy", "The Lumineers"));
    ml.add(new Song("Riptide", "Vance Joy"));
    ml.add(new Song("Oceans", "Seafret"));
    ml.add(new Song("Angela", "The Lumineers"));
    ml.add(new Song("White Lie", "The Lumineers"));
    System.out.println("Contents: " + ml.songList());
    ml.play();
    System.out.println("Queue: " + ml);
    ml.playShuffle();
    System.out.println("Queue: " + ml);
    ml.playShuffle();
    System.out.println("Queue: " + ml);
    ml.playShuffle();
    System.out.println("Queue: " + ml);
  }
}

class Song{
  private String artist_;
  private String song_;
  private long song_id_;
  public Song(String artist, String song){
    artist_ = artist;
    song_ = song;
    song_id_ = HashSong(song_ + artist_);
  }
  //simple hash function for set of song id
  private long HashSong(String s1){
    long ret_val = 0;
    for(int c1 = 0; c1 < s1.length(); c1++){
      ret_val = 17 * ret_val + s1.charAt(c1);
    }
    return ret_val;
  }
  public long getSID(){
    return song_id_;
  }
  public String toString(){
    return song_ + " - " + artist_;
  }
}

class MusicList{
  private Set<Long> song_id;
  private ArrayList<Song> songs;
  private LinkedList<Song> queue;
  public MusicList(){
    song_id = new HashSet<Long>();
    songs = new ArrayList<Song>();
    queue = new LinkedList<Song>();
  }
  public void add(Song s){
    if(!song_id.contains(s.getSID())){
      songs.add(s);
      song_id.add(s.getSID());
    }
  }
  public ArrayList<Song> songList(){
    return songs;
  }
  public void play(){
    for(int c1 = 0; c1 < songs.size(); c1++){
      queue.add(songs.get(c1));
    }
  }
  public void playShuffle(){
    queue.clear();
    Random random = new Random();
    ArrayList<Song> helper_list = new ArrayList<Song>(songs);
    for(int c1 = 0; c1 < helper_list.size(); c1++){
      int h1 = random.nextInt(helper_list.size());
      int h2 = random.nextInt(helper_list.size());
      Song temp = helper_list.get(h1);
      helper_list.set(h1, helper_list.get(h2));
      helper_list.set(h2, temp);
    }
    for(int c1 = 0; c1 < helper_list.size(); c1++){
      queue.add(helper_list.get(c1));
    }
  }
  public void finishSong(){
    queue.removeFirst();
  }
  public String toString(){
    return queue.toString();
  }
}
