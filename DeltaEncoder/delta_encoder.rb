#!/usr/bin/env ruby

class Integer
  def negative?
    self < 0
  end
end

class DeltaCompression
  def self.encode(plain)
    delta = 0
    pieces = plain.split(//).map{ |x| x.ord }
    pieces.each_with_index do |x, i|
      original = x 
      pieces[i] -= delta
      delta = original
    end
    pieces.each_with_index { |c, i| pieces[i] = (c%0xff)+1 if c.negative? }
    pieces.map{|x| x.chr}.join
  end

  def self.decode(encoded)
    delta = 0
    pieces = encoded.split(//).map { |x| x.ord }
    pieces.each_with_index { |c, i| pieces[i] = -((c^0xff)+1) if c > 0x80 }
    pieces.each_with_index do |x, i|
      pieces[i] += delta
      delta = pieces[i]
    end
    pieces.map{|x| x.chr}.join
  end
end

p = (0x20..0x7f).map{|x| x.chr}.sort_by{rand}.join
e = DeltaCompression.encode(p)
d = DeltaCompression.decode(e)
p p == d
