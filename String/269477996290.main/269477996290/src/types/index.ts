export interface ResourceType {
  id: string;
  name: string;
  description?: string;
  createdAt: Date;
  iconUrl?: string;
}

export interface Resource {
  id: string;
  title: string;
  typeId: string;
  content: string;
  author: string;
  createdAt: Date;
  updatedAt: Date;
  fileUrl?: string;
  tags?: string[];
}